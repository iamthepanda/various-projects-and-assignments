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
	${OBJECTDIR}/_ext/1962443507/dayOfYear.o \
	${OBJECTDIR}/_ext/1962443507/person.o \
	${OBJECTDIR}/_ext/1962443507/personnel.o \
	${OBJECTDIR}/_ext/1962443507/student.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/inheritancepersonstudent

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/inheritancepersonstudent: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/inheritancepersonstudent ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/1962443507/dayOfYear.o: ../../School/CSC\ 340/inheritanc-person-student/dayOfYear.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1962443507
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1962443507/dayOfYear.o ../../School/CSC\ 340/inheritanc-person-student/dayOfYear.cpp

${OBJECTDIR}/_ext/1962443507/person.o: ../../School/CSC\ 340/inheritanc-person-student/person.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1962443507
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1962443507/person.o ../../School/CSC\ 340/inheritanc-person-student/person.cpp

${OBJECTDIR}/_ext/1962443507/personnel.o: ../../School/CSC\ 340/inheritanc-person-student/personnel.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1962443507
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1962443507/personnel.o ../../School/CSC\ 340/inheritanc-person-student/personnel.cpp

${OBJECTDIR}/_ext/1962443507/student.o: ../../School/CSC\ 340/inheritanc-person-student/student.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1962443507
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1962443507/student.o ../../School/CSC\ 340/inheritanc-person-student/student.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/inheritancepersonstudent

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
