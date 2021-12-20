SDCC=sdcc
CPU=z80
OBJ=os.rel
DATALOC=0xC000
BIN=os.bin

all: $(BIN)

os.ihx: os.c sys.rel ui.rel ps2.rel sprite.rel audio.rel music.rel music_tracks.rel sound.rel sound_samples.rel ui.rel \
			zorblaxx_app.rel zorblaxx_asteroids.rel zorblaxx_explosions.rel zorblaxx_player.rel zorblaxx_trails.rel zorblaxx_pickups.rel
	$(SDCC) -m$(CPU) --data-loc $(DATALOC) $^

%.rel: %.c
	$(SDCC) -m$(CPU) --data-loc $(DATALOC) -c $<	

%.hex: %.ihx
	mv $< $@

%.bin: %.hex
	srec_cat $< -intel -o $@ -binary
	rm -f *~ *.ihx *.lk *.lst *.map *.noi *.rel *.sym *.hex
	mv $(BIN) bin/$(BIN)
	rm -rf asm/*
	mv *.asm asm/

clean:
	rm -f *~ *.asm *.ihx *.lk *.lst *.map *.noi *.rel *.sym *.hex *.bin
