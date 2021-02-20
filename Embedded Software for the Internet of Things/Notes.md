- Embedded Software for the Internet of Things
    - Embedded Computing
        - Embedded Computer Systems:: any device that includes a programmable computer but it's not itself intended to be a general purpose computing system.
        - Constraint embedded applications must meet
            - Complex algorithms
            - User interface
            - Real time:: if data isn't ready by a certain time, system breaks.
            - Multirate:: may have several real time activities going on at the same time
            - Manufacturing cost
            - Power and energy
        - Microprocessors are a very efficient way to implement digital systems
        - CPUs are
            - flexible
            - efficient
            - highly optimized
        - Cyber-Physical System:: combines physical devices (plants) with computers that control the plant
            - the embedded computer is the cyber part
        - External Constraints
            - how much hardware
            - how do we meet deadlines
            - how do we minimize power consumption
            - how do we design for upgradeability
            - does it really work?
        - Embedded Computer Design is difficult because
            - complex testing
            - limited observability and controllability
            - restricted development environments
        - Performance:: their program must meet its deadline
        - Real Time Computing:: science and art of programming to deadlines
        - 
        - The Embedded System Design Process
        - Design Process Stack
            - Requirements
            - Specification
            - Architecture
            - Components
            - System Integration
        - We proceed in 2 phases
            - we gather an informal description from the customers (Requirements)
            - we refine the requirements to begin designing the system architecture (Specifications)
        - One good way to refine at least the UI portion of a system's requirements is to build a mock-up
            - Mock-up:: should give the customer a good idea of the system
            - After requirements form, check for internal consistency
        - Specifications must be
            - understandable
            - unambiguous
            - example:: UML
        - Architecture:: plan for the overall structure of the system that will be used to design the components
            - example:: Block Diagram
    - 
    - Instruction Set
        - IS:: Program's interface to the hardware
            - characteristics
                - fixed vs variable length
                - addressing models
                - numbers of operands
                - types of operations supported
            - is the key to analysing the performance of programs
        - We can also characterize processors by instruction execution
            - single-issue:: executes one instruction at a time
            - multiple-issue
                - superscalar
                - VLIW (very long instruction word)
        - Programming Model:: set of registers available to programmers
        - CPUs with one chip
            - microcontroller
                - small CPU
                - some ROM for program storage
            - system-on-chip
                - larger processor with on-chip RAM
                - supplemented by off-chip memory
        - 
        - Assembly Languages
            - 1 instruction per line
            - labels start in first column
            - instructions start in the second column
            - comments run from the designated character at the end of the line
        - Assembler must also provide pseudo-ops
            - pseudo-ops:: help programmer to create complete assembly programs
        - 
        - VLIW processors:: CPUs execute faster if they can execute more than 1 instruction at a time
            - If the operands of 1 instruction depend on the result of a previous one, CPU cannot start the new instruction
            - rely on the compiler to identify sets of instructions that can be executed in parallel
            - are smaller and consume less power
            - efficiency:: can easily be leveraged by digital signal processing software
            - very well suited to many signal processing and multimedia applications
            - A set of instruction is bundled together into a VLIW packet
            - Data-dependency:: is a relationship between the data operated on by instruction
        - 
        - ARM processors
            - architecture:: RISC
            - standard ARM word:: 32bit long
            - word may be divided into four 8bit bytes
            - general-purpose registers:: 16 $[r0, ..., r15]$
            - We must consider both arithmetic and logical instructions as well as instructions for reading and writing memory
                - ARM is a load-store architecture
            - CPSR:: current program status register, holds information about: negative, zero, carry, overflow
                - used to easily check result of arithmetic operations.
            - How do we get an address?
                - add or subtract to the PC a constant:: distance between current instruction and desired location
            - 
            - Function frames:: C uses Frame mechanism to pass parameter between functions
                - register holds frame pointer (FP), points to top of frame
                - element within frame are accessed using offset from FP.
                    - $[fp, \#-n]$ takes $n^{th}$ location from FP.
            - Procedure linkage:: convention used to pass values in or out procedures
                - to ensure any function may call any other
            - Stack Pointer:: defines the end of the current frame
            - When a new program is called:: SP and FP are modified to push another frame onto the stack
    - 
    - CPUs
        - I/O devices have some analog (nonelectric) component
        - Data registers:: values that are treated as data by the device
        - Status registers:: info about device's operations
        - Microprocessors can provide programming support for I/O in 2 ways
            - I/O instructions
            - memory-mapped I/O
        - To read a device register:
```c
#define DEV1 0x1000
// ...
int peek (char *location) {
	return *location;
}
dev_status = peek(DEV1);	// read the device register```
        - To write to the status register:
            - ```c
#define DEV1 0x1000
// ...
void poke (char *location, char newval) {
	(*location) = newval;	// write to location
}
poke(DEV1, 8);				// write 8 to dev register
```
        - How to communicate with devices in a program
            - The simplest way is to communicate with busy-wait I/O, but it's extremely inefficient.
        - Polling:: asking I/O whether it is finished by reading its status register.
        - 
        - Interrupt mechanism allows
            - device to signal the CPU
            - device to force execution of a particular piece of code
            - concurrency, which make very efficient use of the CPU
            - When interrupt occurs
                - Program counter's value is changed to point to an INTERRUPT HANDLER routine
        - Because the CPU checks for interrupts at every instruction, it can respond quickly to service requests from devices.
        - There are 2 ways in which interrupts can be generalized to handle multiple devices
            - interrupt priorities:: allow to recognize the importance of each interrupt
            - interrupt vectors:: allow the interrupting device to specify its handler
            - e can change priority by connecting it to a different interrupt request line
        - Masking:: priority mechanism that ensure that low priority interrupt does not occur when a higher priority interrupt is being handled
            - NMI - Non maskable interrupt:: The highest priority interrupt, usually interrupts caused by power failure.
        - Vectors provide flexibility in a different dimension - the ability to define the interrupt handler that should service a request from a device.
            - The device stores its vector number
            - There is no fixed relationships between vector numbers and interrupt handlers
        - Interrupt handling process
            - CPU checks for pending interrupts at the beginning of an instruction. It answers the highest-priority interrupt, which has a higher priority than that given in the interrupt priority register.
            - Device receives the acknowledgement and sends the CPU its interrupt vector.
            - CPU looks up the device handler address in the interrupt vector table using the vector as an index. A subroutine-like mechanism is used to save the current value of the PC and possibly other internal CPU state, such as general-purpose registers.
            - Software (device driver) may save additional CPU state. It then performs the required operations on the device. It then restores any saved state and executes the interrupt return instruction.
            - The interrupt return instruction restores the PC and other automatically saved states to return execution to the code that was interrupted.
            - Interrupt overhead
                - the interrupt itself has overhead similar to a subroutine call.
                - the interrupt requires extra cycles to acknowledge the interrupt and obtain the vector from the device.
                - the interrupt handler will save and restore CPU registers that were not automatically saved by the interrupt.
                - the interrupt return instruction incurs a branch penalty as well as the time required to restore the automatically saved state.
        - Exception
            - is:: an internally detected error
            - example:: division by zero, resets, undefined instructions and illegal memory accesses.
            - the event is similar to an interrupt, except that is generated inside the CPU.
            - requires:: both prioritization and vectoring. Must be prioritized because a single operation may generate more than one exception. Vectoring provides a way for the user ot specify the handler for the exception condition.
        - Traps
            - also known as software interrupt
            - is:: an instruction that explicitly generates an exception condition.
            - example:: enter supervisor mode. Must be controlled to maintain security.
        - 
        - Co-processors
            - provides flexibility at the instruction set level
            - are attached to the CPU
            - implement some of the instructions
        - 
        - Memory System Mechanism
            - Memory Management Units (MMUs)
                - perform address translations that provide a larger virtual memory space in a small physical memory (**memory mapping**)
                    - not common in embedded systems
                - used to:: provide virtual addressing
                    - keeps track of which logical address are
                        - in main memory
                        - kept in secondary storage device
                - when CPU requests an address that is not in main memory it throws an exception (page fault)
                    - the handler reads the requested location from the secondary storage device into main memory
                - Address Translation
                    - Segmented
                        - described by its start address and size
                            - allowing different segments of different size
                        - MMU maintain a segment register that describes the currently active segment
                            - register points to the base of the current segment
                            - address extracted is used as the offset
                            - physical address is formed by adding the segment base to the offset
                    - Paging
                        - each segment is divided into pages
                        - logical address is divided into two section
                            - page number
                            - offset
                        - Page number is an index into a page table
                            - stores physical address for the start of each page
                            - kept in main memory
                        - efficiency may be increased by caching
                            - translation lookaside buffer:: a cache for address translation
                            - MMU reads the TLB to check whether a page number is currently in the TLB cache.
                    - some extensions to both segmenting and paging are useful for virtual memory
                        - at minimum, a present bit is necessary to show whether the logical segment or page is currently in physical memory
                        - a dirty bit shows whether the page/segment has been written to
                        - permission bits are often used
                            - memory protection
                            - pages/segments may be readable but not writable
                            - pages/segments may be accessible only by the supervisor
            - Caches
                - widely used to speed up read and write operations in memory systems
                - is:: a small, fast memory that holds copies of some of the contents of main memory.
                - Cache controller:: mediates between the CPY and the memory system comprised of the cache and main memory.
                - We can classify cache misses into
                    - Compulsory miss (cold miss):: occurs the first time a locations is used
                    - Capacity miss:: caused by a too-large working set
                    - Conflict miss:: when two locations map to the same location in the cache
                - Average memory access time
                    - let $$h$$ be the hit rate, follows that \\(1-h\\) is the miss rate
                    - formula:: \\(t_{av} = ht_{cache} + (1-h)t_{main}\\)
                - Modern CPUs may use multiple levels of cache
                    - first-level is closest to the CPU, the second-level feeds the first-level cache.
                    - average access time:: \\(t_{av} = h_1t_{L1} + (h_2-h_1)t_{L2} + (1-h_2)t_{main}\\)
                    - Replacement policies
                        - Least recently used (LRU):: throw out the block that has been used farthest in the past
                        - Random replacement
                    - Direct-mapped cache
                        - simplest way to implement a cache
                        - consists of cache blocks, each of which includes
                            - a tag to show which memory location is represented
                            - a data field holding the contents
                            - a valid tag to show whether the contents are valid
                        - an address is divided into 3 sections
                            - index:: selects cache block
                            - tag:: compared against the tag value in the selected block
                            - offset:: selects the requested memory location in the data field
                        - Writes are more complicated than reads because w have to update the main memory as well as the cache
                        - Policies
                            - write-through
                                - every writes changes bot cache and main memory
                                - ensures cache and memory are consistent
                                - Drawback:: generates main memory traffic
                            - write-back
                                - we write only when we remove a location from the cache
                        - limitations
                            - Conflict misses:: if two popular location in a program maps onto the same block we will not gain the full benefits of the cache.
                    - Set-associative cache
                        - characterized by the number of banks
                        - a set is formed by all the blocks that share the same index
                        - a cache request is sent to all banks simultaneously
                            - if any has the location, cache reports a hit
                        - provides higher hit rates but can be slightly slower
        - 
        - CPU performance
            - how fast can the CPU execute commands?
            - influenced by:: pipelining and caching
            - Cache performance
                - cache are invisible in the programming model, but they have a profound effect on performance
                - cache miss penalty
                    - extra time to access memory location not cached
                    - amount of variation depends on the system architecture
            - Pipelining
                - several instructions are executed in parallel
                - greatly increases the efficiency of the CPU
                - Some sequences of instruction can disrupt the pipelining
            - Stalls
                - data stall:: one-cycle-per-instruction completion rate does not hold in every case
                - control stall:: referred to as the branch penalty decision whether to take the conditional branch is not made until the 3rd clock cycle of that instruction execution
        - 
        - CPU Power Consumption
            - Power is energy consumption per unit time
                - heat generation depends on power consumption
                - battery life depends on energy consumption
                    - energy required for a computation is independent of the speed with which we perform that work
            - Power consumption characteristics of components are derived from circuits used to build components
            - CMOS consumption
                - 
                - almost all digital systems are built upon power consumption
                    - dynamic:: use of power when circuit is changing its outputs. We can reduce power consumption by freezing logic's inputs
                    - static:: transistors draws current even if is off (leakage)
            - Power saving strategies
                - CPUs can be used at reduced voltage levels
                - can be operated at a lower clock frequency to reduce power
                - may internally disable certain function units that are not required
                - some CPUs allow units to be totally disconnected from the power supply
            - Power management modes
                - static:: invoked by the programmer instruction
                    - power down mode
                    - reduce power consumption, but the transition consumes time and energy
                - dynamic:: invoked by the CPU automatically
                    - when CPU do not need some sections it turns them off
            - Program-level power management
                - Dynamic voltage and frequency scaling (DVFS)
                    - optimizes dynamic power consumption
                        - speed of CMOS or power supply voltage
                        - power consumption of CMOS \\(\alpha\\) (proportional) \\(V^2\\)
                    - reduce voltage to the lowest level that provides the performance
                        - adjust voltage and clock speed
                - Race-to-dark
                    - minimize static power consumption
                        - run as fast as possible and shut down the CPU
                            - good if leakage is very high
                - can be used in combination
                    - \\[E_{tot} = {\displaystyle \int_{0}^{T} P(t)\ dt} = {\displaystyle \int_{0}^{T}} \displaystyle \Large[\small P_{dyn}(t) + P_{static}(t)\Large]\small \ dt\\]
    - 
    - Computing Platforms
        - Hardware
            - We need additional components other than CPU and memory
                - a DMA controller:: provides direct memory access
                - timers:: are usually used by the OS for a variety of purposes
                - multiple busses:: connect CPU, memory to devices
            - single-chip platform:: puts all the components for a basic computing platform on a single chip
            - microcontroller:: single chip that includes a CPU, memory, and I/O devices
        - Software
            - Much of the software in an embedded system will come from outside sources
                - Hardware vendors generally provide a basic set of platform
                    - i.e. components to encourage use of their hardware
                - platform software:: provides core functions, utilities
                    - low-level functions depend on architecture
                        - e.g interrupt vectors, etc.
        - Bus
            - allows:: CPU, memory, devices to communicate
                - shared communication medium
            - is
                - a set of wires
                - a communications protocol
            - CPU serves as the bus master
                - initiates all transfers
                    - reads and writes data and instructions form memory
                    - initiates all reads or writes on I/O devices
            - Bus protocol
                - determines how devices communicate
                    - four-cycle handshake
                        - ensures that when one device is ready to transmit, the other is ready to receive
                        - a pair of wires dedicated to the handshake
                            - enq (enquiry)
                            - ack (acknowledge)
                            - extra wires are use for the data transmit
                        - Steps
                            - device 1 raises its output to signal and enquiry:: device 2 gets ready to listen for data
                            - when device 2 is ready to receive:: it raises its output to signal an ack, device 1 can transmit and 2 can receive
                            - once the data transfer is complete:: device 2 lowers its output, signaling that it has received the data
                            - after seeing that ack has been released:: device 1 lowers its output
            - Bus transaction:: read or write on a bus
                - the operation of a bus transaction is governed by the bus protocol
                - most modern busses use a clock
                    - clock:: synchronize operations of devices on the bus
                        - the bus clock frequency is significantly slower than the CPU
                - Handshake between the CPU and other system components
                    - Clock:: provides synchronization to the bus components
                    - R/W':: true when the bus is reading and vice versa
                    - Address:: a-bit signal that transmits the address for an access
                    - Data:: n-bit signal that can carry data to or from the CPU
                    - Data ready:: signals when the values on the data bundle are valid
                - timing diagram:: shows how the signals on a bus vary over the time
                    - to be sure that signals go to their proper values at the proper times
        - Direct Memory Access (DMA)
            - performs data transfers  _without executing instructions_ 
                - CPU sets up transfer
                - DMA engine fetches, writes
            - is a separate unit
            - by default, CPU is bus master and initiates transfer
                - DMA must become bus master to perform its work
                - CPU can't use bus while DMA operates
            - the DMA requires the CPU to provide two additional bus signals
                - Bus request
                - Bus grant
                - the DMA uses them to gain control of the bus using a classic four-cycle handshake
                    - bus request is asserted by the DMA controller
                    - bus grant is asserted by the CPU when the bus is ready
                        - CPU will finish all pending bus transactions before granting control of the bus to the DMA controller
            - once DMA controller is bus master:: it can perform reads and writes using the same bus protocol as with any CPU-drive bus transaction
            - after the transaction is finished:: the DMA controller deasserts the bus request
            - CPU controls the DMA operation through registers in the DMA controller
                - a typical DMA controller includes the following three registers
                    - starting address register:: specifies where the transfer is to begin
                    - length register:: specifies the number of words to be transferred
                    - status register:: allows the DMA controller to be operated by the CPU
            - The CPU initiates a DMA transfer by
                - setting the starting address and lenght registers
                - then writing the status register to set its start transfer bit
            - After the DMA operation is complete:: the DMA controller interrupts the CPU to tell it that the transfer is done
            - The CPU cannot use the bus during a DMA transfer
            - Once the CPU needs the bus:: it stalls until the DMA controller returns bus mastership to the CPU
            - DMA controllers can occupy the bus for only a few cycles at a time
                - prevents the CPU from idling for too long
        - Memory devices and systems
            - several different types of memory
                - DRAM
                - SRAM
                - Flash
            - each type of memory comes in varying
                - capacities
                - widths
            - The address for that bit is split into two sections: row and column
            - SDRAM Operation
                - two control signals tell the DRAM when those address bits are valid
                    - Row Address Select (RAS)
                    - Column Address Select (CAS)
            - Memory controller
                - the interface between the CPU and the memory components
                - hides the detailed timing of different memory components
            - Read-only memories
                - are programmed with fixed data
                    - program code, and perhaps some data, does not change over time
                    - flash memory is the dominant form of ROM
                        - flash memory can be erased and rewritten
                        - can keep the boot-up code in a protected block
        - 
        - Choosing a Computing Platform
            - CPU
                - there are many different architectures:: choice of instruction sets, features, different clock speed, bus data width, integrated peripherals, and so on
                - consider the software that will execute on the machine
            - Bus
                - bus may be more of a limiting factor than the CPU
                - pay attention to the required data bandwidths to be sure that the bus can handle the traffic
            - Memory
                - memory size depends on both the required data volume and program size
                - memory speed is crucial in determining system performance
            - Input and Output devices
                - which and how many I/O devices?
                - choose a platform that includes I/O devices we do need
        - Intellectual Property (IP)
            - is something that we can own but not touch, e.g. software, netlists, and so on
            - we also need to acquire IP to make that hardware useful
                - Hardware IP
                    - schematics for the printed circuit board
                    - artwork files for the printed circuit board
                    - a bill for materials that lists the required components
                - Software IP
                    - a compiler for the processor
                    - a version of Linux for the processor
        - Development Environment
            - much of the software development for an embedded system is done on a PC
                - target:: the hardware on which the code will finally run
                    - includes a small amount of software to talk to the host system
                - the host and the target are frequently connected by a USB
                - host can
                    - load programs into the target
                    - start and stop program execution on the target
                    - examine memory and CPU registers
            - cross-compiler:: runs on one type of machine but generates code for another
            - host-target debuggers
                - target provides the basic hooks for debugging
                - host creates more sophisticated user interface
            - testbench program:: helps to debug embedded code
                - generates inputs to stimulate a piece of code
                - compares the outputs against expected values
        - Watchdog timer
            - use a timer to monitor the correct operation of software
                - timer's rollover output is connected to the system reset
                - the software reinitializes the counter
                - a reset during operation indicates some type of software error or fault
        - Software debuggers
            - software debugging can be done by compiling and executing the code on a PC
                - but at some point it become necessary to run code on the embedded hardware platform
            - embedded systems are not friendly programming environments
                - the USB port found on most evaluation boards is one of the most important debugging tools
                - a monitor program residing on the target provides basic debugger functions
            - Breakpoint
                - allows stop execution, examine and change system state
                - the breakpoint instruction is replaced with a subroutine call to the monitor program
                - when the PC reaches that address, control is returned to the monitor program (breakpoint handler)
                - breakpoint handler
                    - saves registers
                    - allows user to examine machine
                    - before returning, restores system state
            - LEDs:: frequently used in debugging, used to show errors
            - In-circuit emulator (ICE)
                - in the center, there is a special version of the microprocessor that allows its internal registers to be read out when it is stopped
                - ICE emulator surrounds this specialized microprocessor with additional logic
                    - allows the user to specify breakpoints and examine and modify the CPU state
        - Logic analyser
            - is an array of inexpensive oscilloscopes
                - the analyser can sample many different signals simultaneously
                - but can display only 0, 1, or changing values for each
            - The logic analyser records the values on the signals into an internal memory
        - System-level performance analysis depends on
            - CPU
            - Cache
            - Bus
            - Main memory
            - I/O device
        - Bandwidth as performance
            - bandwidth
                - the rate at which we can move data
                - applies to several components
                    - Memory
                    - Bus
                    - CPU fetches
            - different parts of the system run at different clock rates
            - different components may have different widths
        - Parallelism
            - speed things up by running several units at once
                - DMA provides parallelism if CPU doesn't need the bus
                    - DMA + bus
                    - CPU
    - 
    - Components for Embedded Programs and Models
        - Different and more challenging than writing typical PC programs
            - must provide rich functionality
            - often run at a required rate to meet system deadlines
            - fit into the allowed amount of memory
            - meet power consumption requirements
        - We have some basic building blocks for our programs
            - State machines
            - Circular buffers
            - Queues
            - ...
        - Finite State Machines
            - Embedded systems react to their inputs, the reaction can be characterized in terms of
                - the **input** received
                - the **current state** of the system
            - Implement the program in a state machine style (as in the hardware design)
            - example: simple belt controller
```c
#define IDLE 0
#define SEATED 1
#define BELTED 2
#define BUZZER 3
switch(state) { /* check the current state */
	case IDLE:
		if (seat){ state = SEATED; timer_on = TRUE; }
		/* default case is self-loop */
		break;
	case SEATED:
		if (belt) state = BELTED; /* won’t hear the buzzer */
		else if (timer) state = BUZZER; /* didn’t put on belt in time */
		/* default case is self-loop */
		break;
	case BELTED:
		if (!seat) state = IDLE; /* person left */
		else if (!belt) state = SEATED; /* person still in seat */
		break;
	case BUZZER:
		if (belt) state = BELTED; /* belt is on---turn off buzzer */
		else if (!seat) state = IDLE; /* no one in seat—turn off buzzer */
		break;
}
```
        - 
        - Circular Buffer
            - Stream-oriented processing
                - data comes in regularly and must be processed on the fly
                    - commonly used in signal processing
                        - new data constantly arrives
                        - each datum has a limited lifetime
            - data structure that lets us handle streaming data in an efficient way
            - in C:
                - use an array as the buffer
                - the variable \\(pos\\) holds the position of the current sample
                    - this variable moves as new values are added to the buffer
```c
#define CMAX 6 /* filter order */
int circ[CMAX]; /* circular buffer */
int pos; /* position of current sample */
void circ_update(int xnew) {
	/* compute the new head value with wraparound; the pos pointer moves from 0 to CMAX-1 */
	pos = ((pos == CMAX-1) ? 0 : (pos+1));
	/* insert the new value at the new head */
	circ[pos] = xnew;
}
```
                - initialization:: set the buffer values and pos to zero
                - return:: the \\(i^{th}\\( value of the buffer
                    - translate the index in temporal order
```c
void circ_init() {
	int i;
	for (i=0; i<CMAX; i++) /* set values to 0 */
		circ[i] = 0; pos=CMAX-1; /* start at tail so first element will be at 0 */
}
int circ_get(int i) {
	int ii;
	/* compute the buffer position */
	ii = (pos - i) % CMAX;
	return circ[ii];
}
```
        - 
        - Signal Flow Graph
            - represents many different filtering structures
                - nodes:: represent either arithmetic or delay operators
                    - the box labeled \\(z^{-1}\\) is a delay operator, performs a time delay of one sample period
                    - the edge labeled with $b_1$ multiplies the output of the delay by \\(b_1\\)
            - Digital filters
                - inputs and outputs are generated at the sample rate
                    - \\(x[n]\\)  and \\(y[n]\\) are sequences indexed by \\(n\\)
            - FIR Filter
                - FIR:: Finite Impulse Response
                - code looks like this
```c
for (i=0, y=0.0; i<N; i++)
	y += x[i] * b[i];```
                - In C:
                    - ```c
void circ_update(int xnew) {
	/* add the new sample and push off the oldest one */
	/* compute the new head value with wraparound; the pos pointer moves from CMAX-1 down to 0 */
	pos = ((pos == 0) ? CMAX-1 : (pos-1));
	/* insert the new value at the new head */
	circ[pos] = xnew;
}
int fir(int xnew) {
	/* given a new sample value, update the queue and compute the filter output */
	int i;
	int result; /* holds the filter output */
	circ_update(xnew); /* put the new value in */
	for (i=0, result=0; i<CMAX; i++)
		result += b[i] * circ_get(i);
	return result;
}
```
            - 
            - IIR Filter
                - IIR:: Infinite Impulse Filter
                - give significantly less numerical noise than another
                - In C:
```c
int iir2(int xnew) {
	int i, aside, bside, result;
	for (i=0, aside=0; i<ZMAX; i++)
		aside += -a[i+1] * circ_get(i);
	for (i=0, bside=0; i<ZMAX; i++)
		bside += b[i+1] * circ_get(i);
	result = b[0] * (xnew + aside) + bside;
	circ_update(xnew); /* put the new value in */
	return result;
}
```
        - 
        - Queues
            - we use queues for data that arrive and depart at unpredictable times
                - queues often referred to as an **elastic buffer**.
            - one way to build a queue is with a linked list
                - allows the queue to grow to an arbitrary size
                    - overhead of dynamic memory allocation
            - another way: use an array to hold all the data
                - circular buffer:: a buffer that always has a fixed number of data
                - queue:: may have varying numbers of elements in it
            - Array based queue in C:
```c
#define Q_SIZE 5 /* your queue size may vary */
#define Q_MAX (Q_SIZE-1) /* this is the maximum index value into the array */
int q[Q_SIZE]; /* the array for our queue */
int head, tail; /* indexes for the current queue head and tail */
void queue_init() {
	/* initialize the queue data structure */
	head = 0;
	tail = 0;
}
void enqueue(int val) {
	if (((tail+1) % Q_SIZE) == head) error("enqueue onto full queue",tail);
	q[tail] = val;
	/* update the tail */
	if (tail == Q_MAX)
		tail = 0;
	else
		tail++;
}
int dequeue() {
	int returnval;
	if (head == tail) error("dequeue from empty queue",head);
	returnval = q[head];
	if (head == Q_MAX)
		head = 0;
	else
		head++;
	return returnval;
}
```
        - 
        - Producer/Consumer
            - Many systems may take in varying amounts of data over time and produce varying amounts
            - The variable-rate output of one stage becomes the variable-rate input of another stage
        - 
        - Models of Programs
            - source code is not a good representation for programs
                - clumsy
                - leaves much information implicit
            - compilers derive intermediate representations
                - to manipulate and optimize the program
            - our fundamental model for program is the control/data flow graph (CDFG)
                - models both data operations and control operations
            - Data Flow Graph
                - is a model of a program with no conditionals
                    - in a high-level programming language, a code segment with no conditionals
                    - with only one entry and exit point
                    - known as  _basic block_ .
                - before we are able to draw the DFG
                    - two assignments to the variable \\(x\\)
                        - we need to rewrite the code in **single-assignment form**, in which a variable appears only once on the left size
                - single-assignment form means
                    - data flow graph is acyclic:: if \\(x\\) is assigned multiple times, then the second assignent would form a cycle in the graph
                - keeping the data flow graph acyclic is important in many types of analyses
            - Control-data flow graph (CDFG)
                - is a sequential representation of the program
                    - there is only one program counter in our execution model of the CDF, operations are not executed in parallel
                - is not necessarily tied to high-level language control structures
                    - we can also build a CDFG for an assembly language program
                - uses data flow graph as an element
                    - adds constructs to describe control
                    - has two types of nodes
                        - data flow:: encapsulates a complete data flow graph to represent a basic block
                        - decision node:: describes all the types of control in a sequential program
                            - jump/branch
                - rectangular nodes represent the basic blocks
                - diamond-shaped nodes represent the conditionals
    - Assembly, linking, and loading
        - Assembly and linking are the last steps in the compilation process
            - Assembly and Linking:: they turn a list of instructions into an image of the program's bits in memory
        - Loading:: puts the program in memory, sot that it can be executed
        - Compilation commands do everything to generate an executable program
        - Most compilers do not directly generate machine code
        - assembler generates:: bit-level representations of instructions — object code, translates labels into addresses
        - linker determines:: the final addresses of instructions and data, because the program may be built from many files
        - Absolute and relative addresses
            - We are creating an executable out of several component files
                - before assembling we need to determine
                    - the length of each module in memory
                    - the order modules be linked into the program
                - Absolute addresses:: the starting address of the program, given by the programmer
                - Relative addresses:: addresses within the module are computed relative to the start of the module, the linker is responsible for translating relative addresses into actual addresses
        - Assemblers
            - Assembler
                - translates opcodes and format the bits in each instruction
                - translates translate labels into addresses
                - handle pseudo-ops (data, etc)
            - labels avoid:: worrying about the locations of instructions and data
                - requires making two passes through the assembly source code
                    - scans the code to determine the address of each label
                    - assembles the instructions using the label values computed in the first pass
                        - each label is looked up in the symbol table, its value substituted into the appropriate place in the instruction
                - symbol table
                    - stores the name of each symbol and its address
                    - built during the first pass
                    - by scanning from the first instruction to the last
                    - Program Location Counter (PLC):: keeps the current location in memory, only to assign memory locations to labels
                        - starting value:: a pseudo-op specifies the origin of the program (e.g ORG in the ARM)
            - The assembler produces an object file
                - COFF (common object file format)
                    - describes the instructions, data, and any addressing information
                    - Includes the symbol table for later use in debugging
            - We should generate relocatable code
                - initialize the PLC to 0 (relative to the start of the file)
                - use extra bits in the object file format to mark relative addresses
            - Linker must modify the generated code
                - replaces the relative value with a correct value for the address
        - Linking
            - Linker
                - allows a program to be stitched together out of several smaller pieces
                - operates on the object files created by the assembler
                - modifies the assembled code to make the necessary links between files
                - handles label addresses
                    - labels can be
                        - both defined and used in the same file
                        - defined in one file but used in other file(s)
            - Entry point:: the place in the file where a label is definet
            - External reference:: the place in the file where the label is used
            - Loader
                - resolves external references based on available entry points
                - the assembler also passes to the linker the symbol table
            - Two phases
                - it determines the address of the start of each object file
                    - Load map file:: gives the order in which files are to be placed in memory
                - it merges all symbol tables into a single table
                    - change the relative addresses in the object files to addresses
                    - if a label cannot be found in the merged symbol table, it is undefined and an error message is produced
        - Dynamically linked libraries
            - some operating systems link modules dynamically at run time
                - shares one copy of the library among all executing programs
                - allows programs to be updated with new versions of libraries
        - Memory Map Design
            - We need to control the placement of data and code
                - important in embedded systems
                - we need to place in specific locations
                    - interrupt vectors and other information for I/O devices
                    - memory management tables
                    - global variables used for communication between devices
        - Reentrant Programs
            - A program is reentrant if
                - it can be interrupted by another call to the function without changing the results of either
                - if the program changes the value of global variables it may give a different result when it is called recursively
    - 
    - Compilation
        - Compilation process
            - understanding how the compiler works, helps you to understand
                - when you cannot rely on the compiler
                - how to meet your performance goals
                    - when to write high-level code and/or assembly code?
        - Compilation strategy:: \\(Compilation = translation + optimization\\)
        - Compiler determines quality of code
            - use of CPU resources
            - memory access scheduling
            - code size
        - Procedure linkage
            - procedures require specialized code
            - Procedure linkage:: is the code used to
                - call and return
                - pass parameters and results
            - Parameters and returns are passed on stack
                - local variables are also stored in the stack
            - Procedures with few parameters may user registers
            - Function frame:: holds the information for a call to a procedure
                - stored in stack
                - stack pointer defines:: the end of the current frame
                - frame pointer defines:: the end of the last frame
            - Frame includes
                - parameters and return values
                - locally declared variables
            - the procedure can refer to an element in the frame by addressing relative to sp (or fp)
            - the compiled code access a local variable by referencing a location within the frame
        - Compiler optimizations
            - Data structures
                - the compiler translates references to data structures into memory addresses
                    - this requires address computations, some can be done at compile time, while others must be done at run time
                    - example: one-dimensional array a[i]
                        - we can create a pointer (aptr) that points to the array's head
                        - we can rewrite the reading of a[i] as:
                        - `*(aptr + i)`
                    - A C struct is implemented as a contiguous block of memory
                        - fields can be accessed using constant offsets to the base address of the structure
            - Function inlining
                - replaces a subroutine call to a function with equivalent code to the function body
                - eliminates procedure linkage overhead
                - increases program size
                - inhibits sharing of the function code in teh cache
                    - the inlined copies are distinct pieces of code, they cannot be represented by the same code in the cache
            - Loop transformations
                - reduce loop overhead
                - increase opportunities for pipelining
                - improve memory system performance
            - Loop unrolling
                - pros
                    - enables some other optimizations
                - cons
                    - same proble as the inlined procedure
                    - may interfere with the cache
                    - code size increase
            - Loop fusion
                - combines two or more loops into a single loop
                    - loops must iterate over the same values
                    - loop bodies must not have dependencies
            - Dead code
                - code that can never be executed
                    - can be identified by reachability analysis:: finding the other statements or instructions from which it can be reached
            - Register allocation
                - choose register to hold each variable
                - determine lifespan of variable in the register
                - given a block of code, we want to minimize the total number of required registers
                - best option:: reuse a register once the value stored in the register is no longer needed
                    - the maximum number of variables in use at any statement determines the maximum number of register required
                - if a section of code requires more register than are available
                    - spill some of the vales out to memory temporarily
                        - write the values to temporary memory locations
                        - reuse those registers in other computations
                        - then reread the old values from the temporary locations to resume work
                    - spilling requires
                        - extra CPU time
                        - uses up both instruction and data memory
                    - putting effort into register allocation to avoid unnecessary register spills
                - we can solve register allocation problems
                    - Conflict graph
                        - each variable in the high-level language code is a node
                        - if they live at the same time, they have an edge between them
                    - Graph coloring
                        - use the smallest number of distinct colors
                            - two directly connected nodes should have different color
                        - NP-complete, but there are efficient heuristic algorithms
            - Operator scheduling
                - In many cases, we have freedom in the order in which we do things
```c
(a + b) * (c - d) 
```
                - different orders of loads, stores, and arithmetic operations ⇒ different execution times on pipelined machines
                - example
```c
w = a + b;	// statement 1
x = c + d;	// statement 2
y = x + e;	// statement 3
z = a - b;	// statement 4``` if we swap statement 3 and 4, and then 2 and 3, we reduce our requirements to three registers```c
w = a + b;	// statement 1
z = a - b;	// statement 2
x = c + d;	// statement 3
y = x + e;	// statement 4
```
            - Instruction scheduling
                - when an instruction that takes more cycles than normal to finish is in the pipeline, the pipeline stall appear that reduce performance
                - Software pipelining
                    - reorder instructions to reduce pipeline stalls
                    - execute other instructions while waiting
                        - some of the instructions are working on the early part of iteration \\(n-1\\)
                        - other are working on iteration \\(n\\)
                - Reservation table:: keeps track of CPU resources during instruction scheduling
            - Interpreter:: translates and executes program statements on-the-fly
            - JIT compiler
                - compiles small sections of code into instructions during program execution
                - eliminates some translation overhead
                - often requires more memory
    - Performance analysis and optimization
        - Program-level performance analysis
            - embedded systems must perform functions in real time
                - we often need to know how fast a program runs
            - analysis of program execution time is also helpful in analysing properties such as power consumption
            - CPU clock rate is a very unreliable metric for program performance
            - the execution time of a program often varies with the input data values, values select different execution paths in the program
            - the cache has a major effect on program performance
                - depends on the input data
            - execution times may vary even at the instruction level
                - floating-point operations are the most sensitive to data value
                - pipeline can also introduce data-dependent variations
        - Measuring execution speed
            - Simulate the execution of the CPU
                - the simulator takes an executable with input data that simulates the execution of that program
            - Measure on real CPU using timer
                - modify the program
                    - reset and start the timer at its start of the code
                    - stop the timer at the end of execution
            - Measure on real CPU using logic analyser
                - requires events visible on the pins
        - Program performance metrics
            - Average case:: typically used in application programming
            - Worst case:: longest time that the program can spend on any input sequence, clearly important for systems that must meet deadlines
            - Best case
        - Analysis of programming performance
            - formula:: \\(execution\ time = program\ path + instruction\ timing\\)
                - program path:: sequence of instructions
                - data dependencies, pipeline behaviour, and caching
            - accurate performance analysis requires
                - assembly/binary code
                - execution platform
        - Instruction timing
            - form the execution path of the program to program's total execution time
                - assume that every instruction takes the same number of clock cycles
                    - count the number of instruction
                    - multiply by the per-instruction execution time
            - not all instructions take the same amount of time
                - floating—point instructions show wide variations in execution time
                - basic multiply and add operations are fast
            - execution times of instructions are not independent
                - execution time of one instruction depends on the instructions around it
                    - the result of one instruction is used in the next instruction
            - the execution time of an instruction may depend on operand values
                - floating-point instruction ⇒ different number of iterations to calculate
        - Measurement-driven performance analysis:: determine the execution time of a program by measuring it
            - need the CPU or its simulator
            - must know data inputs that give worst or best case performance
            - still an important method for performance analysis
        - Program traces
            - the record of the execution path of a program
                - instrument the program
                - save information about the path
            - requires modifying the program
            - trace files are large
            - widely used for cache analysis
        - Profiling
            - counts the number of times that procedures or basic blocks in the program are executed
            - two major ways to profile a program
                - adding instructions that increment a location every time the program passes that point in the program
                - sample the program counter during execution
            - adds relatively little overhead to the program, gives us information about where the program spends most of its time
        - Physical performance measurement
            - requires hardware instrumentation
            - the most direct method
                - start a timer when the PC reaches the program's start
                - stop the timer when it reaches the program's end
            - a logic analyser or an oscilloscope
                - watch for signals that mark various points in the execution of the program
            - Simulation-base performance measurement
                - A CPU simulator takes a memory image and performs the operation on that memory image that the actual CPU would peform
                - Cycle-accurate simulator
                    - can determine the exact number of clock cycles required for execution
                    - takes into account all the possible behaviours of the microarchitecture that may affect execution time
                - Instruction-level simulator
                    - functionally simulates instructions but does not provide timing information
                    - it has a complete model of the processor, including the cache
        - Basic loop optimizations
            - loops are good targets for optimization
            - Code motion
                - lets us move unnecessary code out of a loop if a computation's result does not depend on operations performed in the loop body
            - Induction variable elimination
                - a variable whose value is derived from the loop iteration variable's value, the compiler often introduces induction variables to implement the loop
```c
for (i = 0; i < N; i++)
	for (j = 0; j < M; j++)
		z[i,j] = b[i,j];
// becomes
for (i = 0; i < N; i++)
	for (j = 0; j < M; j++) {
		zbinduct = i*M + j;
		*(zptr + zbinduct) = *(bptr + zbinduct);
	}
// we do not need to compute zbinduct afresh each time
for (i = 0; i < N; i++) 
	for (j = 0; j < M; j++) {
		*(zptr + zbinduct) = *(bptr + zbinduct);
		zbinduct++;
	}
```
            - Strength reduction
                - helps us reduce the cost of a loop iteration
                    - example: in integer arithmetic, we can use a shift rather than a multiplication by 2, if the shift is faster than the multiply, we probably want to perform the substitution
```c
 y = x * 2
 // becomes
 y = x << 1
 ```
        - Cache oriented loop optimizations
            - loop nest
            - because loops use large quantities of data, cache conflicts are common
    - 
    - Embedded Real-Time Operating Systems (RTOS)
        - Operating System control is required to switch between processes, makes it much easier to satisfy timing requirements
        - Reactive systems
            - respond to external events
                - engine controller
                - seat belt monitor
            - requires real-time response
                - system architecture
                - program implementation
            - Real-Time Operating Systems (RTOSs)
                - allocates resources using algorithm that take real time into account
                    - general-purpose operating systems, in contrast, generally allocate resources without regard to time — miss deadlines
        - Task
            - is a functional description of a connected set of operations
            - can also mean collection of processes
            - we will use it to mean a set of real-time programs that may communicate
        - Process
            - unique execution of a program
                - several copies of a program may run simultaneously or at different times
                - a process has its own state
                    - registers
                    - memory
                - operating system manages processes
        - In RTOS the processes run in the same address space
        - Threads:: processes that share the same address space
        - The compression engine as a multi-rate system
            - multiple rates:: the need to receive and send data at different rates
            - asynchronous input:: we do know, when the input will arrive (user interfaces)
        - When several different timing requirements, the control structure become complex
        - Multi-rate systems
            - Implementing code that satisfies timing requirements is even more complex when multiple rates of computation must be handled
                - tasks may be synchronous or asynchronous
                - synchronous tasks may recur at different rates
                - processes run at different rates based on computational needs of the tasks
        - Real-time systems
            - perform a computation to conform to external timing constraints
            - deadline frequency
                - periodic
                - aperiodic
            - deadline type
                - hard:: failure to meet deadline causes system failure
                - soft:: failure to meet deadline causes degraded response
                - firm:: late response is useless but some late responses can be tolerated
            - Timing specifications on processes
                - Release time:: time at which process becomes ready
                - Deadline
                    - time at which process must finish
                    - aperiodic:: measured from the initiation time
                    - periodic:: some time other than the end of the period
                - Period:: time between successive executions
                - Rate:: reciprocal of period
                - Hyperperiod:: the least common multiple (LCM) of the periods of the processes
                - Response time of a process:: is the time at which the process finishes
                    - if the schedule meets its requirements, the response time will be before the end of the process' period
                - Jitter of a task:: allowable variation in the completion of the task
            - Timing violations
                - What happens if a process doesn't finish by its deadline?
                    - hard deadline:: system fails if missed
                    - soft deadline:: user may notice, but system doesn't necessarily fail
                - Take a variety of actions when a deadline is missed
                    - Safety-critical systems, e.g. take compensatory measures such switching into a special safety mode
                    - Systems for which safety is not as important, e.g. completely ignore the failure
        - Task graphs
            - Task:: connected set of processes
                - may have data dependencies that must execute in certain order
            - Task graph:: shows data/control dependencies
                - before a process can become ready, all the processes on which it depends must complete and send their data to it
                - all processes must finish before the end of the period
            - Communication among processes at different rates
                - task graph assumes that all processes in each task run at the same rate, tasks do not communicate
                - In reality, some amount of inter-task communication is necessary
                    - it's hard to require immediate response for multi-rate communication
        - CPU usage metrics
            - CPU utilization
                - fraction of the CPU that is doing useful work
                - often calculated assuming no scheduling overhead
                - \\[U = \text{Utilization} = \displaystyle \frac{\displaystyle \sum^{t_2}_{t_1}T(t)}{t_2 - t_1} = \displaystyle \frac {\text{CPU time for useful work}} {\text{total available CPU time}}\\]
        - Process execution characteristics
            - Operating systems determine the process that runs next
            - Scheduling:: choosing the order of running processes
            - Process execution time:: execution time in absence of preemption
                - worst-case, best-case execution time may be useful in some cases
                - possible time units: seconds, clock cycles
                - sources of variation
                    - data dependencies
                    - memory system
                    - CPU pipeline
        - State of a process
            - executing on the CPU
            - ready to run
            - waiting for data
        - Scheduling policy:: how processes are selected from the ready state to the running state
        - Scheduling problem
            - Can we meet all deadlines?
                - must be able to meet deadlines in all cases
            - How much CPU power do we need to meet our deadlines?
            - For some types of timing requirements for a set of processes we cannot utilize 100% of the CPU's execution time on useful work
            - For some scheduling policies we can deliver higher CPU utilization than others, even for the same timing requirements
        - Schedulability and overhead
            - the scheduling process consumes CPU time
                - not all CPU time is available for processes
            - Scheduling overhead must be taken into account for exact schedule
                - may be ignored if it is a small fraction of total execution time
        - Running periodic processes
            - we need to find a programming technique that allows us to run periodic processes
                - While loop implementation
                    - simples implementation: process = subroutine
                    - ```c
while ( TRUE ) {
	p1();
	p2();
}```
                        - no control over execution timing, it does not control the rate at which the processes executed
                - Timed loop implementation
                    - ```c
void pall() {
	p1();
	p2();
}``` encapsulate all processes in a single function that implements the task set
                        - make the execution time of an iteration equal to the desired period
                        - A timer is a much more reliable way
                            - use the timer to generate periodic interrupts that call pall() function
                - Multiple timers implementation
                    - each task has its own function
                    - each task has its own timer
                        - may not have enough timers to implement all the rates
                    - ```c
void pA() {		/* rate A */
	p1();
	p3();
}
void pB() {		/* rate B */
	p2();
	p4();
	p5();
}```
                - Timer + counter implementation
                    - use a software count to divide the timer, then execute processes at rates that are simple multiples of each other
                    - when the rates are not related by a simple ration the counting process becomes more complex
                    - ```c
int p2count = 0;
void pall() {
	p1();
	if ( p2count >= 2 ) {
		p2();
		p2count = 0;
	}
	else 
		p2count++;
	p3();
}```
        - Operating Systems
            - controls resources
                - who get the CPU
                - when I/O takes place
                - how much memory is allocated
            - the most important resource is the CPU
                - CPU access is controlled by the scheduler
            - Structure
                - OS needs to keep track of
                    - process priorities
                    - scheduling state
                    - process activation record
                - Processes may be created
                    - statically before system starts
                    - dynamically during execution
        - Preemptive real-time operating systems
            - RTOS executes processes based upon timing requirements
                - the most reliable way to meet timing requirements accurately
                    - build a preemptive operating system
                    - use priorities to control what process runs at any given time
            - Preemptive scheduling
                - timer interrupt gives CPU to kernel
                    - Time quantum
                        - the length of the timer period
                        - is the smallest increment in which we can control CPU activity
                    - Kernel
                        - determines what process is running
                        - decides what task runs next
                        - performs context switch to new context
        - Context switching
            - Context:: set of registers that defines a process
            - Context switching:: switching from one process' register set to another
            - Record:: the data structure that holds the state of the process
            - Use assembly language to switch between processes
        - Priority-driven scheduling
            - each process has a priority
            - CPU goes to highest-priority process that is ready
            - priorities determine scheduling policy
                - fixed priority
                - time-varying priority
            - Periodic process:: execution on every period
            - Aperiodic process:: executes on demand
                - analysing aperiodic process sets is harder, must consider worst-case combinations of processes activations
            - Period:: interval between process activations
            - Initiation interval:: reciprocal of period
            - Initiation time:: time at which process becomes ready
            - Deadline:: time at which process must finish
            - Scheduling metrics
                - how do we evaluate a scheduling policy
                    - Ability to satisfy all deadlines
                    - CPU utilization
                        - percentage of time devoted to useful work
                    - Scheduling overhead
                        - time required to make scheduling decision
            - Rate Monotonic Scheduling (RMS)
                - widely-used, analysable scheduling policy
                - a static scheduling policy
                    - assigns fixed priorities to processes, that are sufficient to efficiently schedule the processes
                - analysis is known as Rate Monotonic Analysis (RMA)
                - RMA Model
                    - All processes run periodically on single CPY
                    - Zero context switch time
                    - No data dependencies between processes
                    - Process execution time is constant
                    - Deadline is at end of period
                    - The highest-priority ready process is always selected for execution
                        - Priorities are assigned by rank order of period
                            - the process with the shortest period being assigned the highest priority
                    - Unrolled schedule
                        - construct a timeline equal in length to the least-common multiple of the process periods
                            - all three periods tart at time zero
                    - sometimes there is no feasible assignment of priorities that guarantees scheduling
                    - total CPU utilization for a set of n tasks is
                        - \\(U = \displaystyle \sum_{i=1}^n \displaystyle \frac {T_i} {\tau_i}\\)
                        - example
                            - P1 has \\(P=4\\)  and \\(t_{\text{execution}} = 2\\)
                            - P2 has \\(P=7\\)  and \\(t_{\text{execution}} = 1\\)
                            - hyperperiod is \\(4 \times 7 = 28\\)
                            - the CPU utilization is $\displaystyle \frac {(1 \times 4) + (2 \times 7)} {28} = 0.64$
                    - Given m tasks and ratio between any two periods less than 2
                        - the CPU utilization $U$ has a least upper bound of $U = m(2^{\frac{1}{m}}-1)$
                - Earliest-deadline-first scheduling (EDF)
                    - dynamic priority scheduling scheme
                    - process closest to its deadline has highest priority
                    - requires recalculating processes at every timer interrupt
                    - can use 100% of CPU, but may fail to miss a deadline
                    - Implementation
                        - on each timer interrupt
                            - compute time to deadline
                            - choose process closest to deadline
                        - generally considered too expensive in practice
            - Fixing scheduling problems
                - change deadlines in requirements
                - reduce execution times of processes
                - get a faster CPU
            - Protocol
        - Scheduling for low power
            - EDF with DFS
                - first set the clock speed to meet the performance goal in the critical interval
                - set clock speed for less-critical intervals in order of importance
        - Semaphores
            - OS primitive for controlling access to critical regions
            - Protocol
                - get access to semaphore with P()
                - perform critical region operations
                - release semaphore with V()
            - Critical region:: section of code that cannot be interrupted by another process
            - 
        - Priority inversion:: low-priority process keeps high-priority process from running
            - can cause deadlock
            - solving priority inversion
                - give priorities to system resources
                - have process inherit the priority of a resource that it requests
                    - low-priority process inherits priority of device if higher
        - 
        - Shared resources and Race condition
            - A process may need to do more than read and write values to and from memory
                - it may need to communicate with an I/O device
                    - it may use shared memory locations to communicate with other processes
            - when dealing with shared resources, special care must be taken
                - problem when two tasks try to write the same location
                    - T1 reads flag and sees 0
                    - T2 reads flag and sees 0
                    - T1 sets flag to 1 and writes location
                    - T2 sets flag to 1 and overwrites location
            - 
