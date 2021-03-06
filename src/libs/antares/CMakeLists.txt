
OMESSAGE("Antares Core library")





set(SRC_MEMORY
	memory/memory.h
	memory/memory.hxx
	memory/memory.cpp
	memory/prefix.cpp
	memory/swapfile.h
	memory/swapfile.cpp)
source_group("memory" FILES ${SRC_MEMORY})

set(SRC_OBJECT
	object/intrusive-reference.h
	object/intrusive-reference.hxx
	object/object.h
	object/object.hxx
	object/object.cpp
	object/ref.h
)
source_group("object" FILES ${SRC_OBJECT})


set(SRC_MATRIX
	array/array1d.h
	array/array1d.cpp
	array/matrix.h
	array/matrix.cpp
	array/matrix.hxx
	array/autoflush.h
	array/correlation.h
	array/correlation.hxx
	array/correlation.cpp)
source_group("array" FILES ${SRC_MATRIX})



set(SRC_STUDY_SCENARIO_BUILDER
	study/scenario-builder/timeseries.cpp
	study/scenario-builder/timeseries.h
	study/scenario-builder/timeseries.hxx
	study/scenario-builder/rules.h
	study/scenario-builder/rules.hxx
	study/scenario-builder/rules.cpp
	study/scenario-builder/sets.h
	study/scenario-builder/sets.hxx
	study/scenario-builder/sets.cpp
	study/scenario-builder/updater.hxx)
source_group("study\\scenario builder" FILES ${SRC_MATRIX})

set(SRC_STUDY_ACTIONS
	study/action/fwd.h
	study/action/action.h
	study/action/action.hxx
	study/action/action.cpp
	study/action/text.h
	study/action/text.hxx
	study/action/settings/suffix-for-area-names.h
	study/action/settings/suffix-for-area-names.hxx
	study/action/settings/suffix-for-area-names.cpp
	study/action/settings/suffix-for-cluster-names.h
	study/action/settings/suffix-for-cluster-names.hxx
	study/action/settings/suffix-for-cluster-names.cpp
	study/action/settings/suffix-for-constraint-names.h
	study/action/settings/suffix-for-constraint-names.hxx
	study/action/settings/suffix-for-constraint-names.cpp
	study/action/settings/decal-area-position.h
	study/action/settings/decal-area-position.hxx
	study/action/settings/decal-area-position.cpp
	study/action/behavior.h
	study/action/behavior.cpp
	study/action/state.h
	study/action/state.cpp
	study/action/context.h
	study/action/context.cpp)
source_group("study\\actions" FILES ${SRC_STUDY_ACTIONS})

set(SRC_STUDY_ACTIONS_HANDLER_ANTARES_STUDY_AREA
	study/action/handler/antares-study/area/create.h
	study/action/handler/antares-study/area/create.hxx
	study/action/handler/antares-study/area/create.cpp
	study/action/handler/antares-study/area/position.h
	study/action/handler/antares-study/area/position.cpp
	study/action/handler/antares-study/area/filtering.h
	study/action/handler/antares-study/area/filtering.cpp
	study/action/handler/antares-study/area/color.h
	study/action/handler/antares-study/area/color.cpp
	study/action/handler/antares-study/area/nodal-optimization.h
	study/action/handler/antares-study/area/nodal-optimization.cpp
	study/action/handler/antares-study/area/reserves.h
	study/action/handler/antares-study/area/reserves.cpp
	study/action/handler/antares-study/area/misc-gen.h
	study/action/handler/antares-study/area/misc-gen.cpp
	study/action/handler/antares-study/area/timeseries.h
	study/action/handler/antares-study/area/timeseries.cpp
	study/action/handler/antares-study/area/ts-generator.h
	study/action/handler/antares-study/area/ts-generator.cpp
	study/action/handler/antares-study/area/ts-node.h
	study/action/handler/antares-study/area/ts-node.hxx
	study/action/handler/antares-study/area/ts-node.cpp
	study/action/handler/antares-study/area/correlation.h
	study/action/handler/antares-study/area/correlation.cpp
	study/action/handler/antares-study/area/correlation-post.h
	study/action/handler/antares-study/area/correlation-post.hxx
	study/action/handler/antares-study/area/correlation-post.cpp

	study/action/handler/antares-study/area/allocation-hydro.h
	study/action/handler/antares-study/area/allocation-hydro.cpp
	study/action/handler/antares-study/area/allocation-hydro-post.h
	study/action/handler/antares-study/area/allocation-hydro-post.hxx
	study/action/handler/antares-study/area/allocation-hydro-post.cpp)
source_group("study\\actions\\handler\\antares study\\area" FILES ${SRC_STUDY_ACTIONS_HANDLER_ANTARES_STUDY_AREA})

set(SRC_STUDY_ACTIONS_HANDLER_ANTARES_STUDY_LINK
	study/action/handler/antares-study/link/create.h
	study/action/handler/antares-study/link/create.hxx
	study/action/handler/antares-study/link/create.cpp
	study/action/handler/antares-study/link/ntc.h
	study/action/handler/antares-study/link/ntc.cpp
	study/action/handler/antares-study/link/hurdles-cost.h
	study/action/handler/antares-study/link/hurdles-cost.cpp
	study/action/handler/antares-study/link/impedances.h
	study/action/handler/antares-study/link/impedances.cpp
	study/action/handler/antares-study/link/comments.h
	study/action/handler/antares-study/link/comments.hxx
	study/action/handler/antares-study/link/comments.cpp
	study/action/handler/antares-study/link/copper-plate.h
	study/action/handler/antares-study/link/copper-plate.cpp
	study/action/handler/antares-study/link/filtering.h
	study/action/handler/antares-study/link/filtering.cpp
	study/action/handler/antares-study/link/unload-data.h
	study/action/handler/antares-study/link/unload-data.hxx
	study/action/handler/antares-study/link/unload-data.cpp)
source_group("study\\actions\\handler\\antares study\\link" FILES ${SRC_STUDY_ACTIONS_HANDLER_ANTARES_STUDY_LINK})

set(SRC_STUDY_ACTIONS_HANDLER_ANTARES_STUDY_THERMAL
	study/action/handler/antares-study/thermal-cluster/create.h
	study/action/handler/antares-study/thermal-cluster/create.hxx
	study/action/handler/antares-study/thermal-cluster/create.cpp
	study/action/handler/antares-study/thermal-cluster/root-node.h
	study/action/handler/antares-study/thermal-cluster/root-node.hxx
	study/action/handler/antares-study/thermal-cluster/root-node.cpp
	study/action/handler/antares-study/thermal-cluster/common.h
	study/action/handler/antares-study/thermal-cluster/common.cpp
	)
source_group("study\\action\\handler\\sntares study\\thermal cluster" FILES ${SRC_STUDY_ACTIONS_HANDLER_ANTARES_STUDY_THERMAL})


set(SRC_STUDY_ACTIONS_HANDLER_ANTARES_STUDY_CONSTRAINT
	study/action/handler/antares-study/constraint/create.h
	study/action/handler/antares-study/constraint/create.hxx
	study/action/handler/antares-study/constraint/create.cpp
	study/action/handler/antares-study/constraint/comments.h
	study/action/handler/antares-study/constraint/comments.hxx
	study/action/handler/antares-study/constraint/comments.cpp
	study/action/handler/antares-study/constraint/data.h
	study/action/handler/antares-study/constraint/data.hxx
	study/action/handler/antares-study/constraint/data.cpp
	study/action/handler/antares-study/constraint/weights.h
	study/action/handler/antares-study/constraint/weights.cpp
	study/action/handler/antares-study/constraint/offsets.h
	study/action/handler/antares-study/constraint/offsets.cpp
	study/action/handler/antares-study/constraint/enabled.h
	study/action/handler/antares-study/constraint/enabled.hxx
	study/action/handler/antares-study/constraint/enabled.cpp
	)
source_group("study\\action\\handler\\antares study\\constraint" FILES ${SRC_STUDY_ACTIONS_HANDLER_ANTARES_STUDY_CONSTRAINT})


set(SRC_AREAS
	study/area.h
	study/area/constants.h
	study/area/area.h
	study/area/area.hxx
	study/area/scratchpad.h
	study/area/scratchpad.cpp
	study/area/area.cpp
	study/area/links.cpp
	study/area/links.h
	study/area/store-timeseries-numbers.cpp
	study/area/list.cpp
	study/area/list.hxx
	)
source_group("study\\area" FILES ${SRC_AREAS})

set(SRC_STUDY_AREA_UI
	study/area/ui.h
	study/area/ui.hxx
	study/area/ui.cpp
	)
source_group("study\\area\\ui" FILES ${SRC_STUDY_AREA_UI})


set(SRC_STUDY_PART_THERMAL
	study/parts/thermal/container.h
	study/parts/thermal/container.hxx
	study/parts/thermal/container.cpp
	study/parts/thermal/series.h
	study/parts/thermal/series.hxx
	study/parts/thermal/series.cpp
	study/parts/thermal/prepro.h
	study/parts/thermal/prepro.hxx
	study/parts/thermal/prepro.cpp
	study/parts/thermal/cluster.h
	study/parts/thermal/cluster.hxx
	study/parts/thermal/cluster.cpp
	)
source_group("study\\part\\thermal" FILES ${SRC_STUDY_PART_THERMAL})

set(SRC_STUDY_PART_WIND
	study/parts/wind/container.h
	study/parts/wind/container.cpp
	study/parts/wind/series.h
	study/parts/wind/series.hxx
	study/parts/wind/series.cpp
	study/parts/wind/prepro.h
	study/parts/wind/prepro.hxx
	study/parts/wind/prepro.cpp
	)
source_group("study\\part\\wind" FILES ${SRC_STUDY_PART_WIND})

set(SRC_STUDY_PART_HYDRO
	study/parts/hydro/container.h
	study/parts/hydro/container.cpp
	study/parts/hydro/series.h
	study/parts/hydro/series.hxx
	study/parts/hydro/series.cpp
	study/parts/hydro/prepro.h
	study/parts/hydro/prepro.cpp
	study/parts/hydro/allocation.h
	study/parts/hydro/allocation.hxx
	study/parts/hydro/allocation.cpp
	)
source_group("study\\part\\hydro" FILES ${SRC_STUDY_PART_HYDRO})

set(SRC_STUDY_UI
	study/ui-runtimeinfos.h
	study/ui-runtimeinfos.cpp
	)
source_group(study\\UI FILES ${SRC_STUDY_UI})

set(SRC_STUDY_PARAMETERS
	study/parameters.h
	study/parameters.hxx
	study/parameters.cpp
	)
source_group("study\\general data" FILES ${SRC_STUDY_PARAMETERS})


set(SRC_STUDY_FINDER
	study/finder.h
	study/finder/finder.cpp
	study/finder/finder.h
	)
source_group("study\\finder" FILES ${SRC_STUDY_FINDER})


set(SRC_STUDY_BINDING_CONSTRAINT
	study/constraint.h
	study/constraint/constraint.h
	study/constraint/constraint.hxx
	study/constraint/constraint.cpp
	)
source_group("study\\constraint" FILES ${SRC_STUDY_BINDING_CONSTRAINT})





set(SRC_LOGS
	logs.h
	logs/logs.h
	logs/logs.hxx
	logs/logs.cpp
	logs/cleaner.h
	logs/cleaner.cpp
	)
source_group("misc\\logs" FILES ${SRC_LOGS})

include_directories("${ANTARES_OSSL_INCLUDE}")
include_directories("${ANTARES_CURL_INCLUDE}")
set(SRC_PROXY
	proxy.h
	proxy/proxy.h
	proxy/proxy.cpp
	)
source_group("misc\\proxy" FILES ${SRC_PROXY})


set(SRC_JIT
	# JIT (Just in Time)
	jit.h
	jit/jit.h
	jit/jit.hxx
	jit/jit.cpp
	)
source_group("misc\\jit" FILES ${SRC_JIT})

set(SRC_INI
	inifile/inifile.h inifile/inifile.hxx inifile/inifile.cpp  inifile.h
	)
source_group("misc\\inifile" FILES ${SRC_INI})

set(SRC_XCAST
	study/xcast.h
	study/xcast/xcast.h
	study/xcast/xcast.hxx
	study/xcast/xcast.cpp
	)
source_group("study\\xcast" FILES ${SRC_XCAST})

set(SRC_TIMEELAPSED
	timeelapsed.h
	timeelapsed/timeelapsed.h
	timeelapsed/timeelapsed.cpp
	)
source_group("misc\\timeelapsed" FILES ${SRC_TIMEELAPSED})

set(SRC_IO
	io/statistics.h
	io/statistics.cpp
	io/file.h
	io/file.cpp
	)
source_group("io" FILES ${SRC_IO})
	


set(SRC
	config.h  constants.h
	# Misc

	locale.h
	locale.cpp

	string-to-double.h
	string-to-double.cpp

	emergency.h emergency.cpp

	# wx-wrapper
	wx-wrapper.h

	# resource
	resources/resources.h
	resources/resources.cpp

	solver.h
	solver.cpp

	# Memory wrapper
	sys/mem-wrapper.h  sys/mem-wrapper.c

	# appdata
	sys/appdata.h
	sys/appdata.cpp
	sys/policy.h
	sys/policy.cpp
	sys/hostname.hxx

	# Host info
	hostinfo.h hostinfo.cpp

	# files & paths
	files/files.h files/files.cpp
	paths/list.h   paths/list.cpp

	# Utils
	utils.h utils.hxx  utils.cpp

	# version
	version.h
	version.cpp

	# all
	study/parts/parts.h

	# Load
	study/parts/load/container.h
	study/parts/load/container.cpp
	study/parts/load/series.h
	study/parts/load/series.hxx
	study/parts/load/series.cpp
	study/parts/load/prepro.cpp
	study/parts/load/prepro.h
	study/parts/load/prepro.hxx

	# Solar
	study/parts/solar/container.h
	study/parts/solar/container.cpp
	study/parts/solar/series.h
	study/parts/solar/series.hxx
	study/parts/solar/series.cpp
	study/parts/solar/prepro.cpp
	study/parts/solar/prepro.h
	study/parts/solar/prepro.hxx

	# Study
	study/header.h
	study/header.hxx
	study/header.cpp
	study/load-options.h
	study/load-options.cpp
	study/runtime/runtime.h
	study/runtime/runtime.hxx
	study/runtime/runtime.cpp
	study/runtime.h
	study/study.h
	study/study.hxx
	study/current.cpp
	study/fwd.h
	study/fwd.cpp
	study.h
	study/estimate.memory-footprint.cpp
	study/study.cpp
	study/correlation-updater.hxx
	study/mps.cpp
	study/study.importprepro.cpp
	study/memory-usage.h
	study/memory-usage.cpp
	study/importlogs.cpp
	study/load.cpp
	study/save.cpp
	study/study.extra.cpp
	study/version.h
	study/version.cpp
	study/cleaner.h
	study/cleaner/cleaner.cpp study/cleaner/versions.h
	study/cleaner/cleaner-v20.cpp
	study/output.cpp
	study/output.h
	study/output.hxx

	# progression
	study/progression/progression.h
	study/progression/progression.hxx
	study/progression/progression.cpp

	# Simulation
	study/simulation.h
	study/simulation.cpp

	# Filter
	study/filter.h
	study/filter.hxx
	study/filter.cpp

	mersenne-twister/mersenne-twister.h
	mersenne-twister/mersenne-twister.hxx
	mersenne-twister/mersenne-twister.cpp

	# Sets
	study/sets.h
	study/sets.hxx
	
	# variable selection
	study/variable-print-info.h
	study/variable-print-info.cpp
)




add_library( libantares-core-calendar STATIC
	# separated target to reduce multiple unit compilations introduced by swap mode
	date.h
	date/date.h
	date/date.cpp
)



macro(ADD_ANTARES_CORE name)
	add_library(libantares-core${name} STATIC
		antares.h
		${SRC_LOGS}
		${SRC_MEMORY}
		${SRC_OBJECT}
		${SRC_JIT}
		${SRC_INI}
		${SRC_IO}
		${SRC_PROXY}
		${SRC_MATRIX}
		${SRC_TIMEELAPSED}
		${SRC_AREAS}
		${SRC_XCAST}
		${SRC_STUDY_AREA_UI}
		${SRC_STUDY_ACTIONS}
		${SRC_STUDY_ACTIONS_HANDLER_ANTARES_STUDY_THERMAL}
		${SRC_STUDY_ACTIONS_HANDLER_ANTARES_STUDY_AREA}
		${SRC_STUDY_ACTIONS_HANDLER_ANTARES_STUDY_LINK}
		${SRC_STUDY_ACTIONS_HANDLER_ANTARES_STUDY_CONSTRAINT}
		${SRC_STUDY_UI}
		${SRC_STUDY_PARAMETERS}
		${SRC_STUDY_FINDER}
		${SRC_STUDY_BINDING_CONSTRAINT}
		${SRC_STUDY_PART_WIND}
		${SRC_STUDY_PART_HYDRO}
		${SRC_STUDY_PART_THERMAL}
		${SRC_STUDY_SCENARIO_BUILDER}
		${SRC}
	)
	target_link_libraries(libantares-core${name}
		yuni-static-core
		yuni-static-uuid
		libantares-core-calendar
		)

	if(WIN32 OR WIN64)
		target_link_libraries(libantares-core${exec_name} ole32 rpcrt4 ) # uuid
	else()
		target_link_libraries(libantares-core${exec_name} uuid)
	endif()

endmacro()

ADD_ANTARES_CORE("")
ADD_ANTARES_CORE("-swap")

set_target_properties(libantares-core-swap PROPERTIES COMPILE_FLAGS " -DANTARES_SWAP_SUPPORT=1")


