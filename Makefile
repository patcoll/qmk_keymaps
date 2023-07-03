default: | keymaps qmk-clean

.PHONY: qmk
qmk: qmk_firmware/Makefile
qmk_firmware/Makefile:
	init-qmk

.PHONY: qmk-clean
qmk-clean:
	cd qmk_firmware && make git-submodule
	qmk clean -a

.PHONY: twoyo-default
twoyo-default: | qmk
	mkdir -p qmk_firmware/keyboards/twoyo
	rsync -avz firmware/twoyo/ qmk_firmware/keyboards/twoyo/

.PHONY: minisub-default
minisub-default: | qmk
	mkdir -p qmk_firmware/keyboards/minisub
	rsync -avz firmware/minisub/ qmk_firmware/keyboards/minisub/

.PHONY: kawaii-default
kawaii-default: | qmk
	mkdir -p qmk_firmware/keyboards/kawaii
	rsync -avz firmware/kawaii/ qmk_firmware/keyboards/kawaii/

.PHONY: relic-default
relic-default: | qmk
	mkdir -p qmk_firmware/keyboards/relic
	rsync -avz firmware/relic/ qmk_firmware/keyboards/relic/

.PHONY: caravan2
caravan2: | qmk
	mkdir -p qmk_firmware/keyboards/caravan2
	rsync -avz firmware/caravan2/ qmk_firmware/keyboards/caravan2/

.PHONY: menhir
menhir: | qmk
	mkdir -p qmk_firmware/keyboards/menhir
	rsync -avz firmware/menhir/ qmk_firmware/keyboards/menhir/

.PHONY: agony
agony: | qmk
	mkdir -p qmk_firmware/keyboards/handwired/patcoll/agony
	rsync -avz firmware/handwired/patcoll/agony/ qmk_firmware/keyboards/handwired/patcoll/agony/

.PHONY: piedmont
piedmont: | qmk
	mkdir -p qmk_firmware/keyboards/handwired/patcoll/piedmont
	rsync -avz firmware/handwired/patcoll/piedmont/ qmk_firmware/keyboards/handwired/patcoll/piedmont/

.PHONY: oxymoron
oxymoron: | qmk
	mkdir -p qmk_firmware/keyboards/oxymoron
	rsync -avz firmware/oxymoron/ qmk_firmware/keyboards/oxymoron/

.PHONY: ca66r3
ca66r3: | qmk
	mkdir -p qmk_firmware/keyboards/ca66r3
	rsync -avz firmware/ca66r3/ qmk_firmware/keyboards/ca66r3/

.PHONY: curio
curio: | qmk
	mkdir -p qmk_firmware/keyboards/curio
	rsync -avz firmware/curio/ qmk_firmware/keyboards/curio/

.PHONY: alphalpha-plus
alphalpha-plus: | qmk
	mkdir -p qmk_firmware/keyboards/alphalpha_plus
	rsync -avz firmware/alphalpha_plus/ qmk_firmware/keyboards/alphalpha_plus/

.PHONY: 45_ats_hot
45_ats_hot: | qmk
	mkdir -p qmk_firmware/keyboards/45_ats_hot
	rsync -avz firmware/45_ats_hot/ qmk_firmware/keyboards/45_ats_hot/

.PHONY: plop
plop: | qmk
	mkdir -p qmk_firmware/keyboards/plop
	rsync -avz firmware/plop/ qmk_firmware/keyboards/plop/

.PHONY: embrace
embrace: | qmk
	mkdir -p qmk_firmware/keyboards/embrace
	rsync -avz firmware/embrace/ qmk_firmware/keyboards/embrace/

.PHONY: apricot
apricot: | qmk
	mkdir -p qmk_firmware/keyboards/lazydesigners/apricot
	rsync -avz firmware/lazydesigners/apricot/ qmk_firmware/keyboards/lazydesigners/apricot/

.PHONY: sst60
sst60: | qmk
	mkdir -p qmk_firmware/keyboards/sst60
	rsync -avz firmware/sst60/ qmk_firmware/keyboards/sst60/

.PHONY: orbital
orbital: | qmk
	mkdir -p qmk_firmware/keyboards/orbital
	rsync -avz firmware/orbital/ qmk_firmware/keyboards/orbital/

.PHONY: m0ii040pcb
m0ii040pcb: | qmk
	mkdir -p qmk_firmware/keyboards/m0ii040pcb
	rsync -avz firmware/m0ii040pcb/ qmk_firmware/keyboards/m0ii040pcb/

.PHONY: cutiepie
cutiepie: | qmk
	mkdir -p qmk_firmware/keyboards/cutiepie
	rsync -avz firmware/cutiepie/ qmk_firmware/keyboards/cutiepie/

.PHONY: paintbrush_avr
paintbrush_avr: | qmk
	mkdir -p qmk_firmware/keyboards/paintbrush_avr
	rsync -avz firmware/paintbrush_avr/ qmk_firmware/keyboards/paintbrush_avr/

.PHONY: bully
bully: | qmk
	mkdir -p qmk_firmware/keyboards/bully
	rsync -avz firmware/bully/ qmk_firmware/keyboards/bully/

.PHONY: firmware
firmware: | twoyo-default minisub-default kawaii-default relic-default caravan2 menhir agony piedmont oxymoron ca66r3 curio alphalpha-plus 45_ats_hot plop embrace apricot sst60 orbital m0ii040pcb cutiepie paintbrush_avr bully
	echo firmware

.PHONY: keymaps
keymaps: | qmk firmware userspace
	init-keymaps

.PHONY: userspace
userspace: qmk_firmware/users/patcoll/patcoll.h
qmk_firmware/users/patcoll/patcoll.h: qmk
	init-userspace

.PHONY: test
test: | default
	build-all-keymaps

.PHONY: clean
clean:
	rm -rf qmk_firmware working_area/*
