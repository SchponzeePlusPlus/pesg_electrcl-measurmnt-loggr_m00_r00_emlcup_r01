DEVICE     = atmega328p
CLOCK      = 9830400
PROGRAMMER = -c arduino -b 115200 -P /dev/cu.usbmodem*
OBJECTS    = main.o
FUSES      = -U hfuse:w:0xde:m -U lfuse:w:0xff:m -U efuse:w:0x05:m

PRJ_SRC_MAIN_DIR = app
OBJ_DIR = obj

MAIN_SOURCE = $(PRJ_SRC_MAIN_DIR)/main.c
MAIN_OBJECT = $(OBJ_DIR)/main.o

ARDUINO_CORE_PATH = C:\Program Files (x86)\Arduino\hardware\arduino\avr\cores\arduino

# Tune the lines below only if you know what you are doing:

AVRDUDE = avrdude $(PROGRAMMER) -p $(DEVICE)
COMPILE = avr-gcc -Wall -Os -DF_CPU=$(CLOCK) -mmcu=$(DEVICE) -I$(ARDUINO_CORE_PATH)

# symbolic targets:
all:	main.hex

.c.o:
	$(COMPILE) -c $< -o $@

.S.o:
	$(COMPILE) -x assembler-with-cpp -c $< -o $@
# "-x assembler-with-cpp" should not be necessary since this is the default
# file type for the .S (with capital S) extension. However, upper case
# characters are not always preserved on Windows. To ensure WinAVR
# compatibility define the file type manually.

$(MAIN_OBJECT): $(MAIN_SOURCE)
	$(COMPILE) -c $< -o $@

flash:	all
	$(AVRDUDE) -U flash:w:main.hex:i

fuse:
	$(AVRDUDE) $(FUSES)

# Xcode uses the Makefile targets "", "clean" and "install"
install: flash fuse

# if you use a bootloader, change the command below appropriately:
load: all
	bootloadHID main.hex

clean:
	rm -f main.hex main.elf $(OBJECTS)

# file targets:
main.elf: $(MAIN_OBJECT)
	$(COMPILE) -o main.elf $(MAIN_OBJECT)

main.hex: main.elf
	rm -f main.hex
	avr-objcopy -j .text -j .data -O ihex main.elf main.hex
	avr-size --format=avr --mcu=$(DEVICE) main.elf
# If you have an EEPROM section, you must also create a hex file for the
# EEPROM and add it to the "flash" target.

# Targets for code debugging and analysis:
disasm:	main.elf
	avr-objdump -d main.elf

cpp:
	$(COMPILE) -E main.c
