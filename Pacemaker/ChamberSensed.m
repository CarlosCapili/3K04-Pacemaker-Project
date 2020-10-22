classdef ChamberSensed < Simulink.IntEnumType
    %ChamberPaced Enumerated type definition for second Pacemaker code letter
    %   Possible choices refer to the atrium,ventricle, both or neither
    
    enumeration
        ATRIUM_S(0)
        VENTRICLE_S(1)
        DUAL_S(2)
        NONE_S(3)
    end
end

