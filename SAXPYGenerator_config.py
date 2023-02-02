import sst

# Define SST core options
sst.setProgramOption("timebase", "1ps")
sst.setProgramOption("stopAtCycle", "0 ns")

# Tell SST what statistics handling we want
sst.setStatisticLoadLevel(4)

# Define the simulation components
comp_cpu = sst.Component("cpu", "miranda.BaseCPU")
comp_cpu.addParams({
  "clock" : "2660MHz",
  "num_cores" : 8,
  "max_reqs_cycle" : 3,
  "application" : "miranda.SAXPYGenerator",
  "verbose" : 0,
  "printStats" : 1,
})

gen = comp_cpu.setSubComponent("generator", "miranda.SAXPYGenerator")
gen.addParams({
  "num_elements" : 1000000,
  "verbose" : 0,
})

# Enable statistics outputs
comp_cpu.enableAllStatistics({"type":"sst.AccumulatorStatistic"})

comp_memctrl = sst.Component("memory", "memHierarchy.MemController")
comp_memctrl.addParams({
  "clock" : "200MHz",
  "network_bw" : "96GB/s",
  "capacity" : "16384MiB",
})
memory = comp_memctrl.setSubComponent("backend", "memHierarchy.simpleMem")
memory.addParams({
  "access_time" : "5 ns",
  "mem_size" : "16384MiB",
})

network = sst.Component("network", "merlin.hr_router")
network.addParams({
  "xbar_bw" : "96GB/s",
  "link_bw" : "96GB/s",
  "input_buf_size" : "2KiB",
  "output_buf_size" : "2KiB",
  "flit_size" : "8B",
  "id" : "0",
  "num_ports" : "2",
  "topology" : "merlin.singlerouter",
  "route_latency" : "300ps",
  "credit_latency" : "300ps",
  "network_bw" : "96GB/s",
})

# Define the simulation links
link_cpu_network_link = sst.Link("link_cpu_network_link")
link_cpu_network_link.connect( (comp_cpu, "network", "300ps"), (network, "port0", "300ps") )
link_cpu_network_link.setNoCut()
                                          
