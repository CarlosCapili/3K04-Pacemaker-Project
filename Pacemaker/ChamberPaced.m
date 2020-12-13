classdef ChamberPaced < Simulink.IntEnumType
    %ChamberPaced Enumerated type definition for first Pacemaker code letter
    %   Possible choices refer to the atrium,ventricle, both or neither
    
    enumeration
        ATRIUM_P(0)
        VENTRICLE_P(1)
        DUAL_P(2)
        NONE_P(3)
    end
end

