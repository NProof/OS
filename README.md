# Chapter 7 : DeadLocks

## System Model

## Deadlock Characterization
### Necessary Conditions
#### Mutex exclusion互斥
#### Hold and wait持有並等待
#### No preemption不可強取豪奪
#### Circular wait循環等待
### Resource-Allocation Graph
request edge AND assignment edge  

## Methods for Handling Deadlocks

## Deadlock Prevention
### Metual Exclusion
### Hold and Wait
協定一  
除非process可以一次取得完成工作所需的全部資源，才允許process持有資源，否則不准持有任何資源  
協定二  
允許process在執行之初可先持有部分資源，一旦要申請新資源，則必須先釋放持有的全部資源，才可以提申請  
### No Preemption
### Circular Wait

## Deadlock Avoidance
### Safe State
### Resource-Allocation-Graph Algorithm
### Banker's Algorithm
#### Available
#### Max
#### Allocation
#### Need
##### Safety Algorithm
```
Work\[] = Available\[]
if( Need(i) <= Work )
Work = Work + Allocation(i)
```
##### Resource-Request Algorithm
```
if( Request(i) <=  Need(i) && Request(i) <=  Available )
{
  Available = Available - Request(i);
  Allocation(i) = Allocation(i) + Request(i);
  Need(i) = Need(i) - Request(i);
}
```

## Deadlock Detection
```
Work\[] = Available\[]
if( Finish(i) ==  false && Request(i) <=  Work )
{
  Work = Work + Allocation(i);
  Finish(i) = true;
}
```

### Single Instance of Each Resource Type
### Several Instances of a Resource Type
### Detection-Algorithm Usage

## Recovery from Deadlock
### Process Termination
### Resource Preemption

## Summary
