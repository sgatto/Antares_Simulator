/*
** Copyright 2007-2018 RTE
** Authors: Antares_Simulator Team
**
** This file is part of Antares_Simulator.
**
** Antares_Simulator is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** There are special exceptions to the terms and conditions of the
** license as they are applied to this software. View the full text of
** the exceptions in file COPYING.txt in the directory of this software
** distribution
**
** Antares_Simulator is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with Antares_Simulator. If not, see <http://www.gnu.org/licenses/>.
**
** SPDX-License-Identifier: licenceRef-GPL3_WITH_RTE-Exceptions
*/






# include "opt_structure_probleme_a_resoudre.h"

# include "../simulation/simulation.h"
# include "../simulation/sim_structure_donnees.h"
# include "../simulation/sim_extern_variables_globales.h"

# include "opt_fonctions.h"

#include <antares/logs.h>
#include <antares/study.h>
#include <antares/emergency.h>

using namespace Antares;
using namespace Yuni;





bool OPT_OptimisationLineaire(  PROBLEME_HEBDO * ProblemeHebdo,
								uint numSpace,
                                CLASSE_DE_MANOEUVRABILITE ClasseDeManoeuvrabilite,
															 	char CalculerLesPmin,
															 	char CalculerLesPmax,
															 	char FaireDerniereOptimisation )
{
int PdtHebdo; int PremierPdtDeLIntervalle; int DernierPdtDeLIntervalle;
int NumeroDeLIntervalle; int LongueurDuPasDeTemps  ; int NombreDePasDeTempsPourUneOptimisation;

LongueurDuPasDeTemps = (int) ClasseDeManoeuvrabilite;

ProblemeHebdo->NombreDePasDeTemps            = ProblemeHebdo->NombreDePasDeTempsRef            / LongueurDuPasDeTemps;
ProblemeHebdo->NombreDePasDeTempsDUneJournee = ProblemeHebdo->NombreDePasDeTempsDUneJourneeRef / LongueurDuPasDeTemps;

if ( ProblemeHebdo->OptimisationAuPasHebdomadaire == NON_ANTARES ) {
  ProblemeHebdo->NombreDePasDeTempsPourUneOptimisation = ProblemeHebdo->NombreDePasDeTempsDUneJournee;
}
else {
  ProblemeHebdo->NombreDePasDeTempsPourUneOptimisation = ProblemeHebdo->NombreDePasDeTemps;
}

NombreDePasDeTempsPourUneOptimisation = ProblemeHebdo->NombreDePasDeTempsPourUneOptimisation;


(ProblemeHebdo->ProblemeAResoudre)->NumeroDOptimisation = PREMIERE_OPTIMISATION;


OPT_NumeroDeJourDuPasDeTemps( ProblemeHebdo );

OPT_NumeroDIntervalleOptimiseDuPasDeTemps( ProblemeHebdo );

OPT_GenererLesDonneesSelonLePasDeTempsDeLaClasseDeManoeuvrabilite( ProblemeHebdo, ClasseDeManoeuvrabilite );



OPT_ConstruireLaListeDesVariablesOptimiseesDuProblemeLineaire( ProblemeHebdo );



OPT_ConstruireLaMatriceDesContraintesDuProblemeLineaire( ProblemeHebdo, numSpace );

OptimisationHebdo:


for ( PdtHebdo = 0 , NumeroDeLIntervalle = 0 ; PdtHebdo < ProblemeHebdo->NombreDePasDeTemps;
      PdtHebdo = DernierPdtDeLIntervalle , NumeroDeLIntervalle++ ) {

	PremierPdtDeLIntervalle = PdtHebdo;
	DernierPdtDeLIntervalle = PdtHebdo + NombreDePasDeTempsPourUneOptimisation;

		
	OPT_InitialiserLesBornesDesVariablesDuProblemeLineaire( ProblemeHebdo, PremierPdtDeLIntervalle, DernierPdtDeLIntervalle, NumeroDeLIntervalle );
	
  








	
	OPT_InitialiserLeSecondMembreDuProblemeLineaire( ProblemeHebdo, PremierPdtDeLIntervalle, DernierPdtDeLIntervalle, NumeroDeLIntervalle );

	

	OPT_InitialiserLesCoutsLineaire( ProblemeHebdo, PremierPdtDeLIntervalle, DernierPdtDeLIntervalle, numSpace );

	
	ProblemeHebdo->numeroOptimisation[NumeroDeLIntervalle]++;
	
	
	if (!OPT_AppelDuSolveurLineaire( ProblemeHebdo, numSpace, NumeroDeLIntervalle )) {
	  logs.debug().appendFormat("Flexibility level: %ld",
	                            ProblemeHebdo->ClasseDeManoeuvrabiliteActive[
															(ProblemeHebdo->ProblemeAResoudre)->NumeroDeClasseDeManoeuvrabiliteActiveEnCours
															]);
	  return false;
	}

	if ( ProblemeHebdo->ExportMPS == OUI_ANTARES || ProblemeHebdo->Expansion == OUI_ANTARES)
		OPT_EcrireResultatFonctionObjectiveAuFormatTXT((void *) ProblemeHebdo, numSpace, NumeroDeLIntervalle);

	
	if (ProblemeHebdo->numeroOptimisation[NumeroDeLIntervalle] == DEUXIEME_OPTIMISATION)
		ProblemeHebdo->numeroOptimisation[NumeroDeLIntervalle] = 0;
}

if ( ProblemeHebdo->OptimisationMUTetMDT == OUI_ANTARES ) {
  
  if ( (ProblemeHebdo->ProblemeAResoudre)->NumeroDOptimisation == PREMIERE_OPTIMISATION ) {	
    if ( ProblemeHebdo->OptimisationAvecCoutsDeDemarrage == NON_ANTARES ) {
      
      OPT_CalculerLesPminThermiquesEnFonctionDeMUTetMDT( ProblemeHebdo );
		}
		else if ( ProblemeHebdo->OptimisationAvecCoutsDeDemarrage == OUI_ANTARES ) {
      OPT_AjusterLeNombreMinDeGroupesDemarresCoutsDeDemarrage( ProblemeHebdo );
		}
		else printf("BUG: l'indicateur ProblemeHebdo->OptimisationAvecCoutsDeDemarrage doit etre initialise a OUI_ANTARES ou NON_ANTARES\n");

    (ProblemeHebdo->ProblemeAResoudre)->NumeroDOptimisation = DEUXIEME_OPTIMISATION;

	if (ProblemeHebdo->Expansion == NON_ANTARES) goto OptimisationHebdo;
  }
  return true;
}

/* L'optimisation hebdomadaire est terminee, on peut fixer la Pmax de la classe de manoeuvrabilite en cours
   si celle-ci est differente de Classe01 */
if ( (ProblemeHebdo->ProblemeAResoudre)->NumeroDOptimisation == PREMIERE_OPTIMISATION && ClasseDeManoeuvrabilite != Classe01) {
	if ( CalculerLesPmax == OUI_ANTARES ) {
	  OPT_AjusterLesPmaxThermiques( ProblemeHebdo, ClasseDeManoeuvrabilite );
	}
}

/* Ajustement des Pmin pour approcher des durees min de marche */
if ( (ProblemeHebdo->ProblemeAResoudre)->NumeroDOptimisation == PREMIERE_OPTIMISATION && ClasseDeManoeuvrabilite == Classe01 ) {
	if ( CalculerLesPmin == OUI_ANTARES ) {
	  OPT_AjusterLesPminThermiques( ProblemeHebdo );
    if ( FaireDerniereOptimisation == NON_ANTARES ) {
			/* Sera utilise dans la 2eme volee des optimisations */
			OPT_SauvegarderLesPminThermiques( ProblemeHebdo );
		}
		else {
		  /* Cas sans reserve J-1: on vient de calculer les Pmin et on fait une reoptimisation avec ces Pmin */
		  (ProblemeHebdo->ProblemeAResoudre)->NumeroDOptimisation = DEUXIEME_OPTIMISATION;
		  goto OptimisationHebdo;
		}
	}
}

return true;
}




