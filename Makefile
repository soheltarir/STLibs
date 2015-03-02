all: libSTLibs.a 

C++             =       gcc -rdynamic
C++FLAGS        =       -g -Wreturn-type -Wall -O2

WORKING_DIR	=	$(shell pwd)

DEFINE          =       -DFOR_UNIX

INC 		+=	-I$(WORKING_DIR)/include

LDFLAGS         =       -shared

ifeq ($(PLATFORM),AS5)
C++		+=	-m32
endif

ifeq ($(PLATFORM),AS5_64)
C++FLAGS	+=	-fPIC
endif

OBJ             =  TimeConvertor.o ParseFile.o

%.cpp: $(WORKING_DIR)/src/%.cpp
	ln -s $< $@

%.o: %.cpp
	$(C++) -c $(C++FLAGS) $(INC) $(DEFINE) $<  -o $@

libSTLibs.a:$(OBJ)
	ar -rv $@ $(OBJ);
	-@echo "*********** SUCCESS *************"

clean:
	-@echo "cleaning .. "
	$(RM) -rf $(PLATFORM)

clean_dependents:
	-@echo "cleaning temporary objects "
	cd $(PLATFORM); $(RM) *.h *.o; cd ..
update:
	-@echo "updating libstratutils.a in $(FLEXSYS)/flex/plugins"
	\cp $(WORKING_DIR)/$(PLATFORM)/libstratutils.a $(FLEXSYS)/flex/plugins/
