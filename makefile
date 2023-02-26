EXECS=danc_analyzer

CC=gcc


MYFILE=Lexical_Analyzer.c


all: ${EXECS}

${EXECS}: ${MYFILE}
	${CC} -o ${EXECS} ${MYFILE}

clean:
	rm -f ${EXECS}
