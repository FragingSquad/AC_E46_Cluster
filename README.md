### BMW E46 Cluster Driver Project

#### Introduction:
Got myself an old BMW E46 Cluster and wanted to use it with Asseto Corsa, the source can be easily adapted to another game


#### Project Overview:
- Objective: Interface the BMW E46 instrument cluster with Assetto Corsa's in-game vehicle data.
- Components:
  1. BMW E46 instrument cluster
  2. Assetto Corsa
  3. Arduino board
  4. CAN transceiver
  5. Power electronics to drive the tachometer 

#### Troubleshooting:
- If the BMW E46 cluster does not work:
  - Make sure that Assetto Corsa is running and on a race.
  - Check the power supply to the cluster, make sur it is set between 13.2-14V (12 can work but lets stay in lead acid battery voltage range).
  - Check the wiring connections for any loose or incorrect connections.
  - Check with Arduino debugger that the frame are received.

#### Resources:
- [Diagram](https://www.bmwgm5.com/E46_IKE_Connections.htm)
- [https://github.com/tsharp42/E46ClusterDriver](https://github.com/tsharp42/E46ClusterDriver)
- [Thaniel](https://www.bimmerforums.com/forum/showthread.php?1887229-E46-Can-bus-project)
- [MS4X](https://www.ms4x.net/index.php?title=Cluster_M3_LED_Retrofitting)
