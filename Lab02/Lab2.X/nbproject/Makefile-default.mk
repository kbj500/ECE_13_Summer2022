#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Lab2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Lab2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=/Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab01/Lab1_part2.X/BOARD.c /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab02/Lab2.X/mml_test.c /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab02/Lab2.X/MatrixMath.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/911812697/BOARD.o ${OBJECTDIR}/_ext/1745941401/mml_test.o ${OBJECTDIR}/_ext/1745941401/MatrixMath.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/911812697/BOARD.o.d ${OBJECTDIR}/_ext/1745941401/mml_test.o.d ${OBJECTDIR}/_ext/1745941401/MatrixMath.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/911812697/BOARD.o ${OBJECTDIR}/_ext/1745941401/mml_test.o ${OBJECTDIR}/_ext/1745941401/MatrixMath.o

# Source Files
SOURCEFILES=/Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab01/Lab1_part2.X/BOARD.c /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab02/Lab2.X/mml_test.c /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab02/Lab2.X/MatrixMath.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/Lab2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX320F128L
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/911812697/BOARD.o: /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab01/Lab1_part2.X/BOARD.c  .generated_files/flags/default/c2967b52fbfdcd6c3b56bdd74ffa3729091cfc74 .generated_files/flags/default/b049a9946035c0d6f8c1361b9c30a33141c1b72d
	@${MKDIR} "${OBJECTDIR}/_ext/911812697" 
	@${RM} ${OBJECTDIR}/_ext/911812697/BOARD.o.d 
	@${RM} ${OBJECTDIR}/_ext/911812697/BOARD.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/911812697/BOARD.o.d" -o ${OBJECTDIR}/_ext/911812697/BOARD.o /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab01/Lab1_part2.X/BOARD.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1745941401/mml_test.o: /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab02/Lab2.X/mml_test.c  .generated_files/flags/default/2f1266af468402ac22c4c2409df6abec9fce396b .generated_files/flags/default/b049a9946035c0d6f8c1361b9c30a33141c1b72d
	@${MKDIR} "${OBJECTDIR}/_ext/1745941401" 
	@${RM} ${OBJECTDIR}/_ext/1745941401/mml_test.o.d 
	@${RM} ${OBJECTDIR}/_ext/1745941401/mml_test.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1745941401/mml_test.o.d" -o ${OBJECTDIR}/_ext/1745941401/mml_test.o /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab02/Lab2.X/mml_test.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1745941401/MatrixMath.o: /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab02/Lab2.X/MatrixMath.c  .generated_files/flags/default/93c47d3a70d6f58435ae497d094cee6758d9692f .generated_files/flags/default/b049a9946035c0d6f8c1361b9c30a33141c1b72d
	@${MKDIR} "${OBJECTDIR}/_ext/1745941401" 
	@${RM} ${OBJECTDIR}/_ext/1745941401/MatrixMath.o.d 
	@${RM} ${OBJECTDIR}/_ext/1745941401/MatrixMath.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1745941401/MatrixMath.o.d" -o ${OBJECTDIR}/_ext/1745941401/MatrixMath.o /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab02/Lab2.X/MatrixMath.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
else
${OBJECTDIR}/_ext/911812697/BOARD.o: /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab01/Lab1_part2.X/BOARD.c  .generated_files/flags/default/eaa7b357ecd8343b411233ac263eb92c22e96a2e .generated_files/flags/default/b049a9946035c0d6f8c1361b9c30a33141c1b72d
	@${MKDIR} "${OBJECTDIR}/_ext/911812697" 
	@${RM} ${OBJECTDIR}/_ext/911812697/BOARD.o.d 
	@${RM} ${OBJECTDIR}/_ext/911812697/BOARD.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/911812697/BOARD.o.d" -o ${OBJECTDIR}/_ext/911812697/BOARD.o /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab01/Lab1_part2.X/BOARD.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1745941401/mml_test.o: /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab02/Lab2.X/mml_test.c  .generated_files/flags/default/a7536e2224b5935f8de81ddc58cfdae57c4da643 .generated_files/flags/default/b049a9946035c0d6f8c1361b9c30a33141c1b72d
	@${MKDIR} "${OBJECTDIR}/_ext/1745941401" 
	@${RM} ${OBJECTDIR}/_ext/1745941401/mml_test.o.d 
	@${RM} ${OBJECTDIR}/_ext/1745941401/mml_test.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1745941401/mml_test.o.d" -o ${OBJECTDIR}/_ext/1745941401/mml_test.o /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab02/Lab2.X/mml_test.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1745941401/MatrixMath.o: /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab02/Lab2.X/MatrixMath.c  .generated_files/flags/default/79d964e70eabe9d853f6fb5dceab6592c4177b25 .generated_files/flags/default/b049a9946035c0d6f8c1361b9c30a33141c1b72d
	@${MKDIR} "${OBJECTDIR}/_ext/1745941401" 
	@${RM} ${OBJECTDIR}/_ext/1745941401/MatrixMath.o.d 
	@${RM} ${OBJECTDIR}/_ext/1745941401/MatrixMath.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1745941401/MatrixMath.o.d" -o ${OBJECTDIR}/_ext/1745941401/MatrixMath.o /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab02/Lab2.X/MatrixMath.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/Lab2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -D__MPLAB_DEBUGGER_SIMULATOR=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/Lab2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)      -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1,--defsym=_min_heap_size=256,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	
else
${DISTDIR}/Lab2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/Lab2.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=256,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	${MP_CC_DIR}/xc32-bin2hex ${DISTDIR}/Lab2.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
