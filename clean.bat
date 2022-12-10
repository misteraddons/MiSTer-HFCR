@echo off
del /s *.bak
del /s *.orig
del /s *.rej
del /s *~
rmdir /s /q targets/mister/db
rmdir /s /q targets/mister/incremental_db
rmdir /s /q targets/mister/output_files
rmdir /s /q targets/mister/simulation
rmdir /s /q targets/mister/greybox_tmp
rmdir /s /q targets/mister/hc_output
rmdir /s /q targets/mister/.qsys_edit
rmdir /s /q targets/mister/hps_isw_handoff
rmdir /s /q sys\.qsys_edit
rmdir /s /q sys\vip
rmdir /s /q verilator\x64
rmdir /s /q verilator\obj_dir
rmdir /s /q verilator\.vs
del build_id.v
del c5_pin_model_dump.txt
del PLLJ_PLLSPE_INFO.txt
del /s *.qws
del /s *.ppf
del /s *.ddb
del /s *.csv
del /s *.cmp
del /s *.sip
del /s *.spd
del /s *.bsf
del /s *.f
del /s *.sopcinfo
del /s *.xml
del *.cdf
del *.rpt
del /s new_rtl_netlist
del /s old_rtl_netlist
pause
