.PHONY:	test
#=========================
# OS and CPU Architecture
#=========================
ARCH=unknown
OS=unknown

ifeq ($(OS), Windows_NT)

else
  ARCH=$(shell uname -m)
  OS=$(shell uname -s)-$(shell uname -r)
endif

CC=gcc
BASE_FLAGS=-Wall
RELEASE_FLAGS:=$(BASE_FLAGS) 
DEBUG_FLAGS:=$(BASE_FLAGS) -Wpadded
LINK_FLAGS=-lncurses

ifndef PREFIX
BUILDDIR:=$(PWD)/Tron-$(OS)-$(ARCH)
else
BUILDDIR:=$(PREFIX)/Tron-$(OS)-$(ARCH)
endif

MOUNT_DIR:=$(PWD)
OBJ_DIR:=$(BUILDDIR)/obj
LOG_DIR:=$(BUILDDIR)/log
BIN_DIR:=$(BUILDDIR)/bin

CSCRIPT=$(CC) $(CFLAGS) -c $< -o $(OBJ_DIR)/$@
LSCRIPT=$(CC) $(LINK_FLAGS) $(OBJS) -o $(BIN_DIR)/tron

TARGETS=event.o \
	key.o \
	mmanager.o \
	entity.o \
	tstdlib.o \
	sys_ncurses.o \
	main_ncurses.o
	#tron.o

OBJS=	$(OBJ_DIR)/event.o \
	$(OBJ_DIR)/key.o \
	$(OBJ_DIR)/mmanager.o \
	$(OBJ_DIR)/entity.o \
	$(OBJ_DIR)/tstdlib.o \
	$(OBJ_DIR)/sys_ncurses.o \
	$(OBJ_DIR)/main_ncurses.o
	#$(OBJ_DIR)/tron.o

all: build_release build_debug

build_release:
	@mkdir 	$(BUILDDIR) \
		$(LOG_DIR) \
		$(OBJ_DIR) \
		$(BIN_DIR)
	$(MAKE) $(TARGETS) CFLAGS=$(RELEASE_FLAGS)
	$(MAKE) link

build_debug:

link:	$(OBJS)
	$(LSCRIPT)
#=======================
#        Objects  
#=======================
tron.o: tron.c
	$(CSCRIPT)

event.o: event.c
	$(CSCRIPT)

key.o: key.c
	$(CSCRIPT)

mmanager.o: mmanager.c
	$(CSCRIPT)

entity.o: entity.c
	$(CSCRIPT)

tstdlib.o: tstdlib.c
	$(CSCRIPT)

sys_ncurses.o: sys_ncurses.c
	$(CSCRIPT)

main_ncurses.o: main_ncurses.c
	$(CSCRIPT)
#=======================
#	Cleaning
#=======================
clean: clean_logs clean_objs clean_bins
	@rmdir $(OBJ_DIR) \
		$(LOG_DIR) \
		$(BIN_DIR) \
		$(BUILDDIR)
clean_bins:
	@rm -f $(BIN_DIR)/tron
clean_objs:
	@rm -f $(OBJS)
clean_logs:
	@rm -f $(LOG_DIR)/*
