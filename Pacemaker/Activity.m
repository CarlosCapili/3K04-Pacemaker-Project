classdef Activity < Simulink.IntEnumType
    %Activity Enumerated type definition for third Pacemaker code letter
    %   Possible choices refer to triggered,inhibited,both or neither
    
    enumeration
        TRIGGERED(0)
        INHIBITED(1)
        DUAL(2)
        NONE(3)
    end
end