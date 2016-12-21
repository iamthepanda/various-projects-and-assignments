#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-MacOSX
CND_DLIB_EXT=dylib
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/1086225844/assign.o \
	${OBJECTDIR}/_ext/1086225844/out_of_bounds.o \
	${OBJECTDIR}/_ext/1086225844/pointer.o \
	${OBJECTDIR}/_ext/1086225844/square.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppapplication_1

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppapplication_1: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppapplication_1 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/1086225844/assign.o: /Users/george/Dropbox/School/Fall\ 2015/CSc\ 340/assign.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1086225844
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1086225844/assign.o /Users/george/Dropbox/School/Fall\ 2015/CSc\ 340/assign.cpp

${OBJECTDIR}/_ext/1086225844/out_of_bounds.o: /Users/george/Dropbox/School/Fall\ 2015/CSc\ 340/out_of_bounds.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1086225844
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1086225844/out_of_bounds.o /Users/george/Dropbox/School/Fall\ 2015/CSc\ 340/out_of_bounds.cpp

${OBJECTDIR}/_ext/1086225844/pointer.o: /Users/george/Dropbox/School/Fall\ 2015/CSc\ 340/pointer.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1086225844
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1086225844/pointer.o /Users/george/Dropbox/School/Fall\ 2015/CSc\ 340/pointer.cpp

${OBJECTDIR}/_ext/1086225844/square.o: /Users/george/Dropbox/School/Fall\ 2015/CSc\ 340/square.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1086225844
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1086225844/square.o /Users/george/Dropbox/School/Fall\ 2015/CSc\ 340/square.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppapplication_1

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
