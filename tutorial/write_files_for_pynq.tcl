cd C:/work/kv260-RISC-V-On-PYNQ/tutorial

file copy -force ./tutorial/tutorial.runs/impl_1/tutorial_wrapper.bit tutorial.bit

file copy -force ./tutorial/tutorial.gen/sources_1/bd/tutorial/hw_handoff/tutorial.hwh tutorial.hwh

write_bd_tcl -force tutorial.tcl
