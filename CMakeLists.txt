# ======================================================================
#  FILE:  $URL$
# ======================================================================
#  PROJECT:             :  plex-mc_watchdog
#  VERSION              :  @VERION@
#  LANGUAGE             :  CMake script
#  AUTHOR               :  @AUTHOR@
#  COPYRIGHT            :  @COPYRIGHT@
#  COMPILER             :  cmake version 3.0.2
#  CREATED              :  @CREATED@
#  CLASS                :  -
#  LAST MODIFIED        :  @LASTMODIFIED@
#  GENERATED FROM MODEL :  -
#  ORIGINAL MODEL AUTHOR:  -
# ----------------------------------------------------------------------
#  @DESCRIPTION@
# ----------------------------------------------------------------------
#  HISTORY
#  $History$
# ======================================================================

cmake_minimum_required(VERSION 3.2)

project(mc_watchdog)

include($ENV{ESROCOS_CMAKE})

#required function call to set up esrocos
esrocos_init()

########### FOR INTEGRATION PROJECTS ##############

#uncomment if you want to add dependencies for the build process (only required in integration projects)
esrocos_add_dependency(PARTITION x86_partition
	                   MODULES mc_watchdog_bip base-types)

########### FOR COMPONENT PROJECTS ################

#uncomment if you want to export a function
esrocos_export_function("Watchdog" "share/taste_components/watchdog")

#uncomment to export PKG-CONFIG-file
esrocos_export_pkgconfig( VERSION 1.0
                          DESCRIPTION "none"
			              REQUIRES "mc_watchdog_bip"
                          LIBS ""
                          STATIC_LIBS "" 
                          C_FLAGS ""
                        ) 
