# ---------------------------------
# Finds module FS
# Adds library to target
# Adds include path
# ---------------------------------
OPTION(DYNAMIC_LINK_OPENVIBE_MODULE_FS "Dynamically link OpenViBE module FS" ON)

IF(DYNAMIC_LINK_OPENVIBE_MODULE_FS)
	SET(OPENVIBE_MODULE_FS_LINKING "")
ELSE(DYNAMIC_LINK_OPENVIBE_MODULE_FS)
	SET(OPENVIBE_MODULE_FS_LINKING "-static")
ENDIF(DYNAMIC_LINK_OPENVIBE_MODULE_FS)

IF(OV_BRANCH_MODULES_FS)
	set(SRC_DIR ${OV_BASE_DIR}/openvibe-modules/fs/${OV_BRANCH_MODULES_FS})
ELSE(OV_BRANCH_MODULES_FS)
	set(SRC_DIR ${OV_BASE_DIR}/openvibe-modules/fs/${OV_TRUNK})
ENDIF(OV_BRANCH_MODULES_FS)

FIND_PATH(PATH_OPENVIBE_MODULES_FS src/fs/defines.h PATHS ${SRC_DIR})
IF(PATH_OPENVIBE_MODULES_FS)
	MESSAGE(STATUS "  Found OpenViBE module FS...")
	INCLUDE_DIRECTORIES(${PATH_OPENVIBE_MODULES_FS}/src/)

	TARGET_LINK_LIBRARIES(${PROJECT_NAME} openvibe-module-fs${OPENVIBE_MODULE_FS_LINKING})

	ADD_DEFINITIONS(-DTARGET_HAS_FS)
ELSE(PATH_OPENVIBE_MODULES_FS)
	MESSAGE(STATUS "  FAILED to find OpenViBE module FS...")
ENDIF(PATH_OPENVIBE_MODULES_FS)
