SDCC=sdcc
CPU=z80
DATALOC=0xC000
SHARED_PATH=../shared/
SHARED_RELS=$(patsubst %.c,build/%.rel,$(wildcard $(SHARED_PATH)*.c))
OUT_DIR=build/
MAIN=os
PROJECT_RELS_1=$(patsubst %.c,build/%.rel,$(wildcard *.c)) 
PROJECT_RELS=$(patsubst build/$(MAIN).rel,,$(PROJECT_RELS_1)) 
TARGET_RELS=$(patsubst build/$(MAIN).rel,,$(wildcard build/*.rel))


all: $(MAIN).bin

$(MAIN).ihx: $(PROJECT_RELS) $(SHARED_RELS)
	$(SDCC) $(DEFINES) -m$(CPU) --data-loc $(DATALOC) -o $(OUT_DIR) $(MAIN).c $(TARGET_RELS)

build/%.rel: %.c 
	$(SDCC) $(DEFINES) -m$(CPU) --data-loc $(DATALOC) -o $(OUT_DIR) -c $<

%.hex: %.ihx
	mv build/$< $@

%.bin: %.hex
	srec_cat $< -intel -o $@ -binary
#	rm -f build/*.rel build/*.lst build/*.sym build/*.lk build/*.map build/*.noi
	mv $(MAIN).bin bin/$(MAIN).bin

clean:
	rm -f build/*
	rm -f bin/*
