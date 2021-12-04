SDCC=sdcc
CPU=z80
OBJ=os.rel
DATALOC=0xC000
BIN=bin/

all: os.bin

os.ihx: os.c sys.rel ui.rel ps2.rel sprite.rel audio.rel music.rel music_tracks.rel ui.rel \
			zorblaxx_app.rel zorblaxx_asteroids.rel zorblaxx_explosions.rel zorblaxx_player.rel zorblaxx_trails.rel
	$(SDCC) -m$(CPU) --data-loc $(DATALOC) $^

%.rel: %.c
	$(SDCC) -m$(CPU) --data-loc $(DATALOC) -c $<	

%.hex: %.ihx
	mv $< $@

%.bin: %.hex
	srec_cat $< -intel -o $@ -binary
	rm -rf *~ *.ihx *.lk *.lst *.map *.noi *.rel *.sym *.hex

clean:
	rm -rf *~ *.asm *.ihx *.lk *.lst *.map *.noi *.rel *.sym *.hex *.bin
