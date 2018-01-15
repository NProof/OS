## Critical-Section Problem
1. entry section
2. remainder section
### Mutual exclusion 互相排斥  
### Progress   
### Bounded waiting  

## Peterson's solution
restricted限制 two processes
```code

do {
  flag[i] = true;
  turn = j;
  while (flag[j] && turn == j);
  
  //critical section
  
  flag[i] = false;
  
  //remainder section
  
}while(true);
```

share :  
int turn;  
boolean flag\[2];

1. Mutual exclusion is preserved保持  
2. The progress requirement is satisfied  
3. The bounded-waiting requirement is met  

## Synchronization Hardware  
```code
boolena test_and_set(boolean *target){
  boolean rv = *target;
  *target = true;
  
  return rv;
}
```
```code
do {
  while (test_and_set( &lock ));
  
  /* critical section */
  
  lock = false;
  
  /* remainder section */
  
  return rv;
} while (true);
```
not as feasible可行的 in a multiprocessor environment  
Disabling禁用 interrupts on a nultiprocessor can be time consuming消費.
atomically原子  

```code
int compare_and_swap(int *value, int expected, int new_value){
  int temp = *value;
  
  if( *value == expected )
    *value = new_value;
    
  return temp;
}
```
```code
do {
  while (compare_and_swap( &lock, 0, 1) != 0);
  
  /* critical section */
  
  lock = 0;
  
  /* remainder section */
  
  return rv;
} while (true);
```
no bounded-waitiong
```code
do {
  waiting[i] = true;
  key = true;
  while (waiting[i] && key)
    key = test_and_set( &lock );
  waiting[i] = false;
  
  /* critical section */
  
  j = ( i+1 ) % n;
  while ( ( j != i ) && ! waiting[j])
    j = ( j+1 ) % n;
  if ( j == i )
    lock = false;
  else
    waiting[j] = false;
    
  /* remainder section */
} while (true);
```

## Mutex Locks
  mutex : mutual exclusion  
  acquire() and release()
```code
do {
  [ acquire lock ]
    /* critical section */
  [ release lock ]
    /* remainder section */
} while(true);
```
disadvantage:
busy waiting -- spinlock
## Semaphores 信號機  
### Semaphores Usage  
counting semaphore
binary semaphore
### Deadlocks and Stravation飢餓  
### Priority Inversion  
