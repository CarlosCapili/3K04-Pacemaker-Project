# DCM
Dump DCM stuff here, and update this later
___
## To-do list
DCM (English only, 3.2.2, 3.2.3, 3.2.4 only 1 and 2, for 3.2.5 display egrams without markers)
___
- [ ] 3.2.3: DCM Utility Functions 
    - [ ] 3.2.3.1: The About function displays the following:
        - [ ] Application model number
        - [ ] Application software revision number currently in use
        - [ ] DCM serial number
        - [ ] Institution name
    - [ ] 3.2.3.2: The Set Clock function shall set the date and time of the device.
    - [ ] 3.2.3.3: The New Patient function shall allow a new device to be interrogated without exiting the software application.    
    - [ ] 3.2.3.4: The Quit function shall end a telemetry session.
___
- [ ] 3.2.4: Printed Reports
    - [ ] 3.2.4.1: A Bradycardia Parameters Report shall be available.
    - [ ] 3.2.4.2: A Temporary Parameters Report shall be available.
    - [ ] Each report shall contain the following header information:
        - [ ] Institution name
        - [ ] Date and time of report printing
        - [ ] Device model and serial number
        - [ ] DCM serial number
        - [ ] Application model and version number
        - [ ] Report name
___
- [ ] 3.2.5: display egrams without markers
    - [ ] 3.2.5.1: The DCM shall be capable of displaying real time and surface ECG data,
which shall be accomplished using the DCM's internal monitor.
    - [ ] 3.2.5.2: The system shall be capable of displaying up to three Real-Time traces
(2 Telemetered, 1 Surface ECG), in a scrollable fashion.
    - [ ] 3.5.2.3: The DCM shall use the DCM's internal strip chart recorder to provide a
means of printing combinations of real time data.
    - [ ] 3.5.2.4: The DCM shall be capable of printing real time telemetered data and a
surface ECG.
    - [ ] 3.5.2.5: The printer shall be capable of simultaneously printing up to three real-
time traces, along with full annotation for display of event markers.
- [ ] 4.7: Real-time Electrograms
    - [ ] Real-time internal electrograms shall be made available from
        - [ ] The atrial and ventricular sense/pace leads.
        - [ ] A surface electrogram.
    - [ ] The real-time electrogram transmission shall be re-initiated if the telemetry
link was broken during the transmission of electrograms and then reestablished
    - [ ] 4.7.1: Electrogram Viewing
        - [ ] The user shall have the option of viewing the electrograms:
            - [ ] On the screen
            - [ ] Through a printed copy
        - [ ] The user shall have the option of selecting which electrograms are viewed
    and the resolution utilized. Internal electrogram (EGM) options provided are the following:
            - [ ] An atrial internal electrogram option shall be provided.
            - [ ] A ventricular internal electrogram option shall be provided.
            - [ ] An atrial and ventricular internal electrogram option shall be provided.
        - [ ] For the surface electrocardiogram (ECG), the user shall have the capability
    to select
            - [ ] The gain utilized (0.5X, 1X, or 2X)
            - [ ] Whether high pass filtering is on
        - [ ] For the internal electrogram (EGM), the display gain shall
            - [ ] Be selectable (0.5X, 1X, or 2X)
            - [ ] Apply to all channels
___
    
- [ ] Develop an interface that includes a welcome screen, including the ability to register a new user (name and password), and to login as an existing user. A maximum of 10 users should be allowed to be stored locally.
___
- [ ] Develop essential aspects of the user interface - with respect to 3.2.2 in PACEMAKER, you should include: 1, 2 (input buttons), 3, 4, and 7.
    - [ ] 3.2.2.1: The user interface shall be capable of utilizing and managing windows for display of text and graphics.
    - [ ] 3.2.2.2: The user interface shall be capable of processing user positioning and input buttons.
    - [ ] 3.2.2.3: The user interface shall be capable of displaying all programmable parameters for review and modification.
    - [ ] 3.2.2.4: The user interface shall be capable of visually indicating when the DCM and the device are communicating.
    - [ ] 3.2.2.7: The user interface shall be capable of visually indicating when a different PACEMAKER device is approached than was previously interrogated.
___
- [ ] Develop interfaces for all of the pacing modes mentioned in Part 1.
    - [ ] AOO 
    - [ ] VOO 
    - [ ] AAI
    - [ ] VVI
___
- [ ] Make provision for storing programmable parameter data for checking inputs - for the purposes of this assignment the parameters we want specifically are: Lower Rate Limit, Upper Rate Limit, Atrial Amplitude, Atrial Pulse Width, Ventricular Amplitude, and Ventricular Pulse Width, VRP, ARP. The complete set is in PACEMAKER document on page 28.
    - [ ] Lower Rate Limit 
    - [ ] Upper Rate Limit 
    - [ ] Atrial Amplitude
    - [ ] Atrial Pulse Width 
    - [ ] Ventricular Amplitude 
    - [ ] Ventricular Pulse Width
    - [ ] VRP
    - [ ] ARP
