default: | keymaps qmk-clean

.PHONY: qmk
qmk: ${QMK_HOME}/Makefile
${QMK_HOME}/Makefile:
	init-qmk

.PHONY: qmk-clean
qmk-clean:
	cd ${QMK_HOME} && make git-submodule
	qmk clean -a

.PHONY: twoyo-default
twoyo-default: | qmk
	mkdir -p ${QMK_HOME}/keyboards/twoyo
	rsync -avz firmware/twoyo/ ${QMK_HOME}/keyboards/twoyo/

.PHONY: minisub-default
minisub-default: | qmk
	mkdir -p ${QMK_HOME}/keyboards/minisub
	rsync -avz firmware/minisub/ ${QMK_HOME}/keyboards/minisub/

.PHONY: kawaii-default
kawaii-default: | qmk
	mkdir -p ${QMK_HOME}/keyboards/kawaii
	rsync -avz firmware/kawaii/ ${QMK_HOME}/keyboards/kawaii/

.PHONY: relic-default
relic-default: | qmk
	mkdir -p ${QMK_HOME}/keyboards/relic
	rsync -avz firmware/relic/ ${QMK_HOME}/keyboards/relic/

.PHONY: caravan2
caravan2: | qmk
	mkdir -p ${QMK_HOME}/keyboards/caravan2
	rsync -avz firmware/caravan2/ ${QMK_HOME}/keyboards/caravan2/

.PHONY: menhir
menhir: | qmk
	mkdir -p ${QMK_HOME}/keyboards/menhir
	rsync -avz firmware/menhir/ ${QMK_HOME}/keyboards/menhir/

.PHONY: agony
agony: | qmk
	mkdir -p ${QMK_HOME}/keyboards/handwired/patcoll/agony
	rsync -avz firmware/handwired/patcoll/agony/ ${QMK_HOME}/keyboards/handwired/patcoll/agony/

.PHONY: piedmont
piedmont: | qmk
	mkdir -p ${QMK_HOME}/keyboards/handwired/patcoll/piedmont
	rsync -avz firmware/handwired/patcoll/piedmont/ ${QMK_HOME}/keyboards/handwired/patcoll/piedmont/

.PHONY: oxymoron
oxymoron: | qmk
	mkdir -p ${QMK_HOME}/keyboards/oxymoron
	rsync -avz firmware/oxymoron/ ${QMK_HOME}/keyboards/oxymoron/

.PHONY: ca66r3
ca66r3: | qmk
	mkdir -p ${QMK_HOME}/keyboards/ca66r3
	rsync -avz firmware/ca66r3/ ${QMK_HOME}/keyboards/ca66r3/

.PHONY: curio
curio: | qmk
	mkdir -p ${QMK_HOME}/keyboards/curio
	rsync -avz firmware/curio/ ${QMK_HOME}/keyboards/curio/

.PHONY: alphalpha-plus
alphalpha-plus: | qmk
	mkdir -p ${QMK_HOME}/keyboards/alphalpha_plus
	rsync -avz firmware/alphalpha_plus/ ${QMK_HOME}/keyboards/alphalpha_plus/

.PHONY: 45_ats_hot
45_ats_hot: | qmk
	mkdir -p ${QMK_HOME}/keyboards/45_ats_hot
	rsync -avz firmware/45_ats_hot/ ${QMK_HOME}/keyboards/45_ats_hot/

.PHONY: plop
plop: | qmk
	mkdir -p ${QMK_HOME}/keyboards/plop
	rsync -avz firmware/plop/ ${QMK_HOME}/keyboards/plop/

.PHONY: embrace
embrace: | qmk
	mkdir -p ${QMK_HOME}/keyboards/embrace
	rsync -avz firmware/embrace/ ${QMK_HOME}/keyboards/embrace/

.PHONY: apricot
apricot: | qmk
	mkdir -p ${QMK_HOME}/keyboards/lazydesigners/apricot
	rsync -avz firmware/lazydesigners/apricot/ ${QMK_HOME}/keyboards/lazydesigners/apricot/

.PHONY: sst60
sst60: | qmk
	mkdir -p ${QMK_HOME}/keyboards/sst60
	rsync -avz firmware/sst60/ ${QMK_HOME}/keyboards/sst60/

.PHONY: orbital
orbital: | qmk
	mkdir -p ${QMK_HOME}/keyboards/orbital
	rsync -avz firmware/orbital/ ${QMK_HOME}/keyboards/orbital/

.PHONY: m0ii040pcb
m0ii040pcb: | qmk
	mkdir -p ${QMK_HOME}/keyboards/m0ii040pcb
	rsync -avz firmware/m0ii040pcb/ ${QMK_HOME}/keyboards/m0ii040pcb/

.PHONY: cutiepie
cutiepie: | qmk
	mkdir -p ${QMK_HOME}/keyboards/cutiepie
	rsync -avz firmware/cutiepie/ ${QMK_HOME}/keyboards/cutiepie/

.PHONY: paintbrush_avr
paintbrush_avr: | qmk
	mkdir -p ${QMK_HOME}/keyboards/paintbrush_avr
	rsync -avz firmware/paintbrush_avr/ ${QMK_HOME}/keyboards/paintbrush_avr/

.PHONY: bully
bully: | qmk
	mkdir -p ${QMK_HOME}/keyboards/bully
	rsync -avz firmware/bully/ ${QMK_HOME}/keyboards/bully/

.PHONY: bully2040
bully2040: | qmk
	mkdir -p ${QMK_HOME}/keyboards/bully2040
	rsync -avz firmware/bully2040/ ${QMK_HOME}/keyboards/bully2040/

.PHONY: monorail
monorail: | qmk
	mkdir -p ${QMK_HOME}/keyboards/monorail
	rsync -avz firmware/monorail/ ${QMK_HOME}/keyboards/monorail/

.PHONY: monorail2
monorail2: | qmk
	mkdir -p ${QMK_HOME}/keyboards/monorail2
	rsync -avz firmware/monorail2/ ${QMK_HOME}/keyboards/monorail2/

.PHONY: cisne
cisne: | qmk
	mkdir -p ${QMK_HOME}/keyboards/cisne
	rsync -avz firmware/cisne/ ${QMK_HOME}/keyboards/cisne/

.PHONY: 3999
3999: | qmk
	mkdir -p ${QMK_HOME}/keyboards/3999
	rsync -avz firmware/3999/ ${QMK_HOME}/keyboards/3999/

.PHONY: grouper
grouper: | qmk
	mkdir -p ${QMK_HOME}/keyboards/grouper
	rsync -avz firmware/grouper/ ${QMK_HOME}/keyboards/grouper/

.PHONY: c11
c11: | qmk
	mkdir -p ${QMK_HOME}/keyboards/c11
	rsync -avz firmware/c11/ ${QMK_HOME}/keyboards/c11/

.PHONY: serendipity
serendipity: | qmk
	mkdir -p ${QMK_HOME}/keyboards/serendipity
	rsync -avz firmware/serendipity/ ${QMK_HOME}/keyboards/serendipity/

.PHONY: haitun2040
haitun2040: | qmk
	mkdir -p ${QMK_HOME}/keyboards/haitun2040
	rsync -avz firmware/haitun2040/ ${QMK_HOME}/keyboards/haitun2040/

.PHONY: infernum
infernum: | qmk
	mkdir -p ${QMK_HOME}/keyboards/infernum
	rsync -avz firmware/infernum/ ${QMK_HOME}/keyboards/infernum/

.PHONY: cool536lc
cool536lc: | qmk
	mkdir -p ${QMK_HOME}/keyboards/cool536lc
	rsync -avz firmware/cool536lc/ ${QMK_HOME}/keyboards/cool536lc/

.PHONY: qezberry
qezberry: | qmk
	mkdir -p ${QMK_HOME}/keyboards/qezberry
	rsync -avz firmware/qezberry/ ${QMK_HOME}/keyboards/qezberry/

.PHONY: oc3anograph3r
oc3anograph3r: | qmk
	mkdir -p ${QMK_HOME}/keyboards/oc3anograph3r
	rsync -avz firmware/oc3anograph3r/ ${QMK_HOME}/keyboards/oc3anograph3r/

.PHONY: cuticle
cuticle: | qmk
	mkdir -p ${QMK_HOME}/keyboards/cuticle
	rsync -avz firmware/cuticle/ ${QMK_HOME}/keyboards/cuticle/

.PHONY: qaz_rp2040
qaz_rp2040: | qmk
	mkdir -p ${QMK_HOME}/keyboards/qaz_rp2040
	rsync -avz firmware/qaz_rp2040/ ${QMK_HOME}/keyboards/qaz_rp2040/

.PHONY: tk40x
tk40x: | qmk
	mkdir -p ${QMK_HOME}/keyboards/lazydesigners/tk40x
	rsync -avz firmware/lazydesigners/tk40x/ ${QMK_HOME}/keyboards/lazydesigners/tk40x/

.PHONY: syndrome
syndrome: | qmk
	mkdir -p ${QMK_HOME}/keyboards/nachie/syndrome
	rsync -avz firmware/nachie/syndrome/ ${QMK_HOME}/keyboards/nachie/syndrome/

.PHONY: denali
denali: | qmk
	mkdir -p ${QMK_HOME}/keyboards/denali
	rsync -avz firmware/denali/ ${QMK_HOME}/keyboards/denali/

.PHONY: firmware
firmware: | twoyo-default minisub-default kawaii-default relic-default caravan2 menhir agony piedmont oxymoron ca66r3 curio alphalpha-plus 45_ats_hot plop embrace apricot sst60 orbital m0ii040pcb cutiepie paintbrush_avr bully monorail monorail2 cisne 3999 bully2040 grouper c11 serendipity haitun2040 infernum cool536lc qezberry oc3anograph3r cuticle qaz_rp2040 tk40x syndrome denali
	echo firmware

.PHONY: keymaps
keymaps: | qmk firmware userspace
	init-keymaps

.PHONY: userspace
userspace: ${QMK_HOME}/users/patcoll/patcoll.h
${QMK_HOME}/users/patcoll/patcoll.h: qmk
	init-userspace

.PHONY: test
test: | default
	build-all-keymaps

.PHONY: clean
clean:
	rm -rf ${QMK_HOME} working_area/*
