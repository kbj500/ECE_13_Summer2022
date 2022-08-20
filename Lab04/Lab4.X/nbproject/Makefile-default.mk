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
FINAL_IMAGE=${DISTDIR}/Lab4.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Lab4.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=/Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab04/Lab4.X/Leds_lab04.c /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab04/Lab4.X/Ascii.c /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab04/Lab4.X/BOARD.c /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab04/Lab4.X/Oled.c /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab04/Lab4.X/OledDriver.c /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab04/Lab4.X/Buttons.c /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab04/Lab4.X/bounce_buttons.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1739681191/Leds_lab04.o ${OBJECTDIR}/_ext/1739681191/Ascii.o ${OBJECTDIR}/_ext/1739681191/BOARD.o ${OBJECTDIR}/_ext/1739681191/Oled.o ${OBJECTDIR}/_ext/1739681191/OledDriver.o ${OBJECTDIR}/_ext/1739681191/Buttons.o ${OBJECTDIR}/_ext/1739681191/bounce_buttons.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1739681191/Leds_lab04.o.d ${OBJECTDIR}/_ext/1739681191/Ascii.o.d ${OBJECTDIR}/_ext/1739681191/BOARD.o.d ${OBJECTDIR}/_ext/1739681191/Oled.o.d ${OBJECTDIR}/_ext/1739681191/OledDriver.o.d ${OBJECTDIR}/_ext/1739681191/Buttons.o.d ${OBJECTDIR}/_ext/1739681191/bounce_buttons.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1739681191/Leds_lab04.o ${OBJECTDIR}/_ext/1739681191/Ascii.o ${OBJECTDIR}/_ext/1739681191/BOARD.o ${OBJECTDIR}/_ext/1739681191/Oled.o ${OBJECTDIR}/_ext/1739681191/OledDriver.o ${OBJECTDIR}/_ext/1739681191/Buttons.o ${OBJECTDIR}/_ext/1739681191/bounce_buttons.o

# Source Files
SOURCEFILES=/Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab04/Lab4.X/Leds_lab04.c /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab04/Lab4.X/Ascii.c /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab04/Lab4.X/BOARD.c /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab04/Lab4.X/Oled.c /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab04/Lab4.X/OledDriver.c /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab04/Lab4.X/Buttons.c /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab04/Lab4.X/bounce_buttons.c



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
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/Lab4.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX320F128H
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
${OBJECTDIR}/_ext/1739681191/Leds_lab04.o: /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab04/Lab4.X/Leds_lab04.c  .generated_files/flags/default/66ea2d131139fc49185111826a4de355b8d59e6e .generated_files/flags/default/b049a9946035c0d6f8c1361b9c30a33141c1b72d
	@${MKDIR} "${OBJECTDIR}/_ext/1739681191" 
	@${RM} ${OBJECTDIR}/_ext/1739681191/Leds_lab04.o.d 
	@${RM} ${OBJECTDIR}/_ext/1739681191/Leds_lab04.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1739681191/Leds_lab04.o.d" -o ${OBJECTDIR}/_ext/1739681191/Leds_lab04.o /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab04/Lab4.X/Leds_lab04.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1739681191/Ascii.o: /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab04/Lab4.X/Ascii.c  .generated_files/flags/default/6221c5ce04d5499c0b3b5dd46243c4fc1a3d2a88 .generated_files/flags/default/b049a9946035c0d6f8c1361b9c30a33141c1b72d
	@${MKDIR} "${OBJECTDIR}/_ext/1739681191" 
	@${RM} ${OBJECTDIR}/_ext/1739681191/Ascii.o.d 
	@${RM} ${OBJECTDIR}/_ext/1739681191/Ascii.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1739681191/Ascii.o.d" -o ${OBJECTDIR}/_ext/1739681191/Ascii.o /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab04/Lab4.X/Ascii.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1739681191/BOARD.o: /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab04/Lab4.X/BOARD.c  .generated_files/flags/default/56ff320b2819cb561a4325a494a1f26e5b00f7f8 .generated_files/flags/default/b049a9946035c0d6f8c1361b9c30a33141c1b72d
	@${MKDIR} "${OBJECTDIR}/_ext/1739681191" 
	@${RM} ${OBJECTDIR}/_ext/1739681191/BOARD.o.d 
	@${RM} ${OBJECTDIR}/_ext/1739681191/BOARD.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1739681191/BOARD.o.d" -o ${OBJECTDIR}/_ext/1739681191/BOARD.o /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab04/Lab4.X/BOARD.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1739681191/Oled.o: /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab04/Lab4.X/Oled.c  .generated_files/flags/default/9dadd077d696ac09ef555d2e9cad9b1a50bfe087 .generated_files/flags/default/b049a9946035c0d6f8c1361b9c30a33141c1b72d
	@${MKDIR} "${OBJECTDIR}/_ext/1739681191" 
	@${RM} ${OBJECTDIR}/_ext/1739681191/Oled.o.d 
	@${RM} ${OBJECTDIR}/_ext/1739681191/Oled.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1739681191/Oled.o.d" -o ${OBJECTDIR}/_ext/1739681191/Oled.o /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab04/Lab4.X/Oled.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1739681191/OledDriver.o: /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab04/Lab4.X/OledDriver.c  .generated_files/flags/default/4bb6be758bab3ba7b4bbc8156b90796ae44dc1b7 .generated_files/flags/default/b049a9946035c0d6f8c1361b9c30a33141c1b72d
	@${MKDIR} "${OBJECTDIR}/_ext/1739681191" 
	@${RM} ${OBJECTDIR}/_ext/1739681191/OledDriver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1739681191/OledDriver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1739681191/OledDriver.o.d" -o ${OBJECTDIR}/_ext/1739681191/OledDriver.o /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab04/Lab4.X/OledDriver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1739681191/Buttons.o: /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab04/Lab4.X/Buttons.c  .generated_files/flags/default/84b6113c98c6167fdd7af24c8576101a6a2684ab .generated_files/flags/default/b049a9946035c0d6f8c1361b9c30a33141c1b72d
	@${MKDIR} "${OBJECTDIR}/_ext/1739681191" 
	@${RM} ${OBJECTDIR}/_ext/1739681191/Buttons.o.d 
	@${RM} ${OBJECTDIR}/_ext/1739681191/Buttons.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1739681191/Buttons.o.d" -o ${OBJECTDIR}/_ext/1739681191/Buttons.o /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab04/Lab4.X/Buttons.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1739681191/bounce_buttons.o: /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab04/Lab4.X/bounce_buttons.c  .generated_files/flags/default/56965d8e3e838b7b795a7d2b9fef3ac48a30311d .generated_files/flags/default/b049a9946035c0d6f8c1361b9c30a33141c1b72d
	@${MKDIR} "${OBJECTDIR}/_ext/1739681191" 
	@${RM} ${OBJECTDIR}/_ext/1739681191/bounce_buttons.o.d 
	@${RM} ${OBJECTDIR}/_ext/1739681191/bounce_buttons.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1739681191/bounce_buttons.o.d" -o ${OBJECTDIR}/_ext/1739681191/bounce_buttons.o /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab04/Lab4.X/bounce_buttons.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
else
${OBJECTDIR}/_ext/1739681191/Leds_lab04.o: /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab04/Lab4.X/Leds_lab04.c  .generated_files/flags/default/f4fc19222aa7cac4a0cbed8e07473f83c4ed200d .generated_files/flags/default/b049a9946035c0d6f8c1361b9c30a33141c1b72d
	@${MKDIR} "${OBJECTDIR}/_ext/1739681191" 
	@${RM} ${OBJECTDIR}/_ext/1739681191/Leds_lab04.o.d 
	@${RM} ${OBJECTDIR}/_ext/1739681191/Leds_lab04.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1739681191/Leds_lab04.o.d" -o ${OBJECTDIR}/_ext/1739681191/Leds_lab04.o /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab04/Lab4.X/Leds_lab04.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1739681191/Ascii.o: /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab04/Lab4.X/Ascii.c  .generated_files/flags/default/f705142216f61efced5433471af8bdaa4208f348 .generated_files/flags/default/b049a9946035c0d6f8c1361b9c30a33141c1b72d
	@${MKDIR} "${OBJECTDIR}/_ext/1739681191" 
	@${RM} ${OBJECTDIR}/_ext/1739681191/Ascii.o.d 
	@${RM} ${OBJECTDIR}/_ext/1739681191/Ascii.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1739681191/Ascii.o.d" -o ${OBJECTDIR}/_ext/1739681191/Ascii.o /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab04/Lab4.X/Ascii.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1739681191/BOARD.o: /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab04/Lab4.X/BOARD.c  .generated_files/flags/default/358c7c48711af566ea46e80b2a5706c3b3eda123 .generated_files/flags/default/b049a9946035c0d6f8c1361b9c30a33141c1b72d
	@${MKDIR} "${OBJECTDIR}/_ext/1739681191" 
	@${RM} ${OBJECTDIR}/_ext/1739681191/BOARD.o.d 
	@${RM} ${OBJECTDIR}/_ext/1739681191/BOARD.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1739681191/BOARD.o.d" -o ${OBJECTDIR}/_ext/1739681191/BOARD.o /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab04/Lab4.X/BOARD.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1739681191/Oled.o: /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab04/Lab4.X/Oled.c  .generated_files/flags/default/bcf16314af3d66f5aa2865648eaf4782db94d335 .generated_files/flags/default/b049a9946035c0d6f8c1361b9c30a33141c1b72d
	@${MKDIR} "${OBJECTDIR}/_ext/1739681191" 
	@${RM} ${OBJECTDIR}/_ext/1739681191/Oled.o.d 
	@${RM} ${OBJECTDIR}/_ext/1739681191/Oled.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1739681191/Oled.o.d" -o ${OBJECTDIR}/_ext/1739681191/Oled.o /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab04/Lab4.X/Oled.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1739681191/OledDriver.o: /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab04/Lab4.X/OledDriver.c  .generated_files/flags/default/ecf59179bc99f562db59aadb16216c58212b9d95 .generated_files/flags/default/b049a9946035c0d6f8c1361b9c30a33141c1b72d
	@${MKDIR} "${OBJECTDIR}/_ext/1739681191" 
	@${RM} ${OBJECTDIR}/_ext/1739681191/OledDriver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1739681191/OledDriver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1739681191/OledDriver.o.d" -o ${OBJECTDIR}/_ext/1739681191/OledDriver.o /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab04/Lab4.X/OledDriver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1739681191/Buttons.o: /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab04/Lab4.X/Buttons.c  .generated_files/flags/default/dc0a3bd96726c0372730de6423edd11db73dd8ce .generated_files/flags/default/b049a9946035c0d6f8c1361b9c30a33141c1b72d
	@${MKDIR} "${OBJECTDIR}/_ext/1739681191" 
	@${RM} ${OBJECTDIR}/_ext/1739681191/Buttons.o.d 
	@${RM} ${OBJECTDIR}/_ext/1739681191/Buttons.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1739681191/Buttons.o.d" -o ${OBJECTDIR}/_ext/1739681191/Buttons.o /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab04/Lab4.X/Buttons.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1739681191/bounce_buttons.o: /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab04/Lab4.X/bounce_buttons.c  .generated_files/flags/default/346ed24b2f2c875be6514bfc8d74e6f3274dd8e5 .generated_files/flags/default/b049a9946035c0d6f8c1361b9c30a33141c1b72d
	@${MKDIR} "${OBJECTDIR}/_ext/1739681191" 
	@${RM} ${OBJECTDIR}/_ext/1739681191/bounce_buttons.o.d 
	@${RM} ${OBJECTDIR}/_ext/1739681191/bounce_buttons.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1739681191/bounce_buttons.o.d" -o ${OBJECTDIR}/_ext/1739681191/bounce_buttons.o /Users/bijayakhadka/Documents/ECE_13/bkhadka/Lab04/Lab4.X/bounce_buttons.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/Lab4.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/Lab4.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC02000:0x1FC02FEF -mreserve=boot@0x1FC02000:0x1FC024FF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_PK3=1,--defsym=_min_heap_size=1024,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	
else
${DISTDIR}/Lab4.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/Lab4.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=1024,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	${MP_CC_DIR}/xc32-bin2hex ${DISTDIR}/Lab4.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
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
