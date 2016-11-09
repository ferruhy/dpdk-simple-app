include $(RTE_SDK)/mk/rte.vars.mk

APP := simple

SRCS-y := simple.c

CFLAGS += -O3

include $(RTE_SDK)/mk/rte.extapp.mk
