  del *.cf *.vcd
  ghdl -a    alu1_behavioral.vhd
  ghdl -a tb_alu1_behavioral-v2.vhd
  ghdl -e    alu1b
  ghdl -e tb_alu1b
  ghdl -r tb_alu1b --stop-time=400ns --disp-time --vcd=tb_alu1b.vcd
  gtkwave tb_alu1b.vcd
