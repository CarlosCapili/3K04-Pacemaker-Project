classdef Activity < Simulink.IntEnumType
    %Activity Enumerated type definition for third Pacemaker code letter
    %   Possible choices refer to triggered,inhibited,both or neither
    
    enumeration
        TRIGGERED_A(0)
        INHIBITED_A(1)
        DUAL_A(2)
        NONE_A(3)
    end
end