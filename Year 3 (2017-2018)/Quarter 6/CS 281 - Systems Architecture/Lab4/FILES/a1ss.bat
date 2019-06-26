  del *.cf *.vcd
  ghdl -a    and_2.vhd
  ghdl -a     or_2.vhd
  ghdl -a    xor_2.vhd
  ghdl -a    mux41b.vhd
  ghdl -a    half_adder_behavioral.vhd
  ghdl -a    full_adders.vhd
  ghdl -a    alu1_sub_structural.vhd
  ghdl -a tb_alu1_sub_structural.vhd
:
  ghdl -e    and_2
  ghdl -e     or_2
  ghdl -e    xor_2
  ghdl -e    mux41
  ghdl -e    half_adder
  ghdl -e    full_adder
  ghdl -e    alu1ss
  ghdl -e tb_alu1ss
  ghdl -r tb_alu1ss --stop-time=200ns --disp-time --vcd=tb_alu1ss.vcd
  gtkwave tb_alu1ss.vcd
