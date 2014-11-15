    .section .text
    .global __bdk_power_burn_dp

__bdk_power_burn_dp:
    sub     sp, sp, 34 * 8
    stp     x10, x11, [sp]
    stp     d0, d1, [sp, 16 * 1]
    stp     d2, d3, [sp, 16 * 2]
    stp     d4, d5, [sp, 16 * 3]
    stp     d6, d7, [sp, 16 * 4]
    stp     d8, d9, [sp, 16 * 5]
    stp     d10, d11, [sp, 16 * 6]
    stp     d12, d13, [sp, 16 * 7]
    stp     d14, d15, [sp, 16 * 8]
    stp     d16, d17, [sp, 16 * 9]
    stp     d18, d19, [sp, 16 * 10]
    stp     d20, d21, [sp, 16 * 11]
    stp     d22, d23, [sp, 16 * 12]
    stp     d24, d25, [sp, 16 * 13]
    stp     d26, d27, [sp, 16 * 14]
    stp     d28, d29, [sp, 16 * 15]
    stp     d30, d31, [sp, 16 * 16]

    fmov d0, #1.0
    fmov d1, #1.0
    fmov d2, #1.0
    fmov d3, #1.0
    fmov d4, #1.0
    fmov d5, #1.0
    fmov d6, #1.0
    fmov d7, #1.0
    fmov d8, #1.0
    fmov d9, #1.0
    fmov d10, #1.0
    fmov d11, #1.0
    fmov d12, #1.0
    fmov d13, #1.0
    fmov d14, #1.0
    fmov d15, #1.0
    fmov d16, #1.0
    fmov d17, #1.0
    fmov d18, #1.0
    fmov d19, #1.0
    fmov d20, #1.0
    fmov d21, #1.0
    fmov d22, #1.0
    fmov d23, #1.0
    fmov d24, #1.0
    fmov d25, #1.0
    fmov d26, #1.0
    fmov d27, #1.0
    fmov d28, #1.0
    fmov d29, #1.0
    fmov d30, #1.0
    fmov d31, #1.0
    mov         x0, 1<<23

loop:
    adr         x11, data
    fmadd       d11, d1, d2, d13
    ldr         d0, [x11], #8
    fmadd       d12, d2, d3, d4
    ldr         d1, [x11], #8
    fmadd       d13, d3, d4, d5
    ldr         d2, [x11], #8
    fmadd       d14, d4, d5, d6
    ldr         d3, [x11], #8
    fmadd       d15, d5, d6, d7
    ldr         d4, [x11], #8
    fmadd       d16, d10, d7, d8
    ldr         d5, [x11], #8
    fmadd       d17, d7, d11, d6
    ldr         d6, [x11], #8
    fmadd       d10, d0, d1, d12
    ldr         d7, [x11], #8

    fmadd       d11, d1, d2, d13
    ldr         d0, [x11], #8
    fmadd       d12, d2, d3, d4
    ldr         d1, [x11], #8
    fmadd       d13, d3, d4, d5
    ldr         d2, [x11], #8
    fmadd       d14, d4, d5, d6
    ldr         d3, [x11], #8
    fmadd       d15, d5, d6, d7
    ldr         d4, [x11], #8
    fmadd       d16, d10, d7, d8
    ldr         d5, [x11], #8
    fmadd       d17, d7, d11, d6
    ldr         d6, [x11], #8
    fmadd       d10, d0, d1, d12
    ldr         d7, [x11], #8

    fmadd       d11, d1, d2, d13
    ldr         d0, [x11], #8
    fmadd       d12, d2, d3, d4
    ldr         d1, [x11], #8
    fmadd       d13, d3, d4, d5
    ldr         d2, [x11], #8
    fmadd       d14, d4, d5, d6
    ldr         d3, [x11], #8
    fmadd       d15, d5, d6, d7
    ldr         d4, [x11], #8
    fmadd       d16, d10, d7, d8
    ldr         d5, [x11], #8
    fmadd       d17, d7, d11, d6
    ldr         d6, [x11], #8
    fmadd       d10, d0, d1, d12
    ldr         d7, [x11], #8

    fmadd       d11, d1, d2, d13
    ldr         d0, [x11], #8
    fmadd       d12, d2, d3, d4
    ldr         d1, [x11], #8
    fmadd       d13, d3, d4, d5
    ldr         d2, [x11], #8
    fmadd       d14, d4, d5, d6
    ldr         d3, [x11], #8
    fmadd       d15, d5, d6, d7
    ldr         d4, [x11], #8
    fmadd       d16, d10, d7, d8
    ldr         d5, [x11], #8
    fmadd       d17, d7, d11, d6
    ldr         d6, [x11], #8
    fmadd       d10, d0, d1, d12
    ldr         d7, [x11], #8

    subs        x0, x0, #1
    b.gt        loop

    ldp     x10, x11, [sp]
    ldp     d0, d1, [sp, 16 * 1]
    ldp     d2, d3, [sp, 16 * 2]
    ldp     d4, d5, [sp, 16 * 3]
    ldp     d6, d7, [sp, 16 * 4]
    ldp     d8, d9, [sp, 16 * 5]
    ldp     d10, d11, [sp, 16 * 6]
    ldp     d12, d13, [sp, 16 * 7]
    ldp     d14, d15, [sp, 16 * 8]
    ldp     d16, d17, [sp, 16 * 9]
    ldp     d18, d19, [sp, 16 * 10]
    ldp     d20, d21, [sp, 16 * 11]
    ldp     d22, d23, [sp, 16 * 12]
    ldp     d24, d25, [sp, 16 * 13]
    ldp     d26, d27, [sp, 16 * 14]
    ldp     d28, d29, [sp, 16 * 15]
    ldp     d30, d31, [sp, 16 * 16]
    add     sp, sp, 34 * 8

    ret
 
.align 7
 data:
.dword 0x42D473508C9FF7F3
.dword 0xC3DB49B8A9ECC40F
.dword 0xC00A7FE1F7E6DE0C
.dword 0x401465330D4281FA
.dword 0x4112D736B68ACF2A
.dword 0x43863228E83C3D40
.dword 0x40C9BDF2560B2F77
.dword 0x42E3071969AD6500
.dword 0x428CCC1BE902F518
.dword 0x41F60213E70A8F65
.dword 0xC2EFA253A7A5CBC2
.dword 0x435D82F16679ABB3
.dword 0xC312AECA5EDF7708
.dword 0xC2A6D0EB82CEE860
.dword 0xC368F3D5C78E2187
.dword 0x42E31B618F607BDC
.dword 0x4164199C648F32B4
.dword 0xC09913DEB3B07092
.dword 0xC1B8D0BF896318F9
.dword 0x408580385D565B2B
.dword 0x40D7A01C883CD6C4
.dword 0x42FCF74153CD7355
.dword 0xC38366FE69C970CA
.dword 0x40DA971FBF909CEE
.dword 0xC321D5B1C3A02E03
.dword 0xC10010D77AC12A20
.dword 0xC0D518EA303513F3
.dword 0x4141F30BDEE9119B
.dword 0x40A9E5239F220AE8
.dword 0xC2555D7764AEB6F7
.dword 0xC2E5B844CD95A89C
.dword 0x429464587A590A63
.dword 0xC0E4B649CBECFEAD
.dword 0x4315854E391EE9A3
.dword 0x41CCC01016437CD0
.dword 0x429AC42FDA4725E3
.dword 0x3FFFB367A21A8419
.dword 0xBFF7A0410A6B9ABC
.dword 0x4189FE6FEA922051
.dword 0xC2FCBE81B3CE9D2E
.dword 0x41B59839E8E86F5B
.dword 0xC0BD4E2804F3042C
.dword 0x43E7F5C5F0AC412A
.dword 0xC01C886827EDBC94
.dword 0xC277F472FA966113
.dword 0xC314EBE86EEB6BFE
.dword 0x40871E5CA2D41FED
.dword 0x43E52A3288ED2D95
.dword 0xC0635C82F29FCCE0
.dword 0x41A6A29BC1190375
.dword 0xC19A010AA4826F3E
.dword 0x4297B0215359F823
.dword 0x402C6066522BC522
.dword 0x427E899F62882EE3
.dword 0xC35E01CFAF2586F3
.dword 0xC278C6BBA706A543
.dword 0x4118C55F15FF8D4A
.dword 0x434605EDCCBEF07D
.dword 0xC31F863D78D35666
.dword 0x4019E31960A6FFC5
.dword 0x409F50EB4E5314AF
.dword 0xC35D102BCD038E8E
.dword 0xC1B8B9355489C76C
.dword 0x4369E3905AAA09D5
.dword 0xC3BE769532D404F3
.dword 0x41A89C8A4356BB2A
.dword 0xC0892C7E072CBF4C
.dword 0x4155D7D8FB637ABA
.dword 0x4334FB774FCDF155
.dword 0x4278BDBC158CC485
.dword 0x401ACA3DAACEC068
.dword 0x41E0DEB3F942CDF0
.dword 0xC176396E3908B875
.dword 0x4339399BD2AF0AB4
.dword 0x41AF6ABE6FD54385
.dword 0xC29320B656F5BDF5
.dword 0x410607B53C03AF45
.dword 0xC3E16C423B1F9785
.dword 0xC36711A2261FB69A
.dword 0x42198C11BE16D933
.dword 0x40E6E9F61EECF408
.dword 0x403E6E16CF7BE98C
.dword 0x437B227D3DAABC48
.dword 0xC0ECDFBE4A4C58A8
.dword 0x413F6AEABCA60C9F
.dword 0x43CDF634A840AEE1
.dword 0x404F13192105AAA7
.dword 0xBFF37A0739E63E28
.dword 0xC0D0D0CEC6D47497
.dword 0xC2104B013C7371AF
.dword 0xC021201BB2B856E7
.dword 0xC013624E4A60D5EE
.dword 0x41417D4EE2F52487
.dword 0x432764A70F1214B8
.dword 0xC271306C3A772B4C
.dword 0xC0D829FDAF12C3D2
.dword 0xC16B40D711AD3934
.dword 0xC3CAF5FFAC4C66CE
.dword 0x43EF7DAAA641AFCF
.dword 0xC1ACBB03412A7CE2
.dword 0x430740A8BC3868E1
.dword 0xC1EC20C7602C32C1
.dword 0xC24D8B2F1306FA04
.dword 0x429E30E734CD5844
.dword 0xC18DB8CC72E08DF4
.dword 0x41DE358C741BB0F6
.dword 0x40503D280B534A20
.dword 0xC233FE7EB9565C43
.dword 0x42F8D2BB4B5A2135
.dword 0xC0F1875FD9DFDCA7
.dword 0x4398A81828212EEE
.dword 0x40AB0330A0D9C17E
.dword 0xC1E14A44205F45AD
.dword 0x4220A235DC9B5A37
.dword 0x43A8403404F1922E
.dword 0x43CBF7D5E6202422
.dword 0xC0F37C49779BBBEF
.dword 0x436CBEB67C9C756B
.dword 0x415E93516A77E597
.dword 0xC0CF154BA6CCC151
.dword 0x405082E8FAFF64DE
.dword 0x41A1410A9411F0D8
.dword 0x401336CEDCAD9721
.dword 0xC00FC22EF7547B98
.dword 0x43B0C43BDDA5C68B
.dword 0x4127FED7078D6755
.dword 0xC35DFBCD5EABE07B
.dword 0xC0B17DC5A4A0EAD0
.dword 0x4305E124B6DDCAE8
.dword 0xC2CA68840623C2A8
.dword 0xC06B81C888B41D1F
.dword 0x40E223AC1D29223B
.dword 0x436B904306CCB8B6
.dword 0x40413FA1AE2217CA
.dword 0xC264CCBB2C58E09A
.dword 0x414A07DF1C17BBBB
.dword 0x406FA08B31526EA9
.dword 0xC173CE06739272D6
.dword 0xC18EED1C6844E72C
.dword 0x3FF4C301BC57F6A2
.dword 0x42329F67EC97D2DD
.dword 0xC2A97B131A31C928
.dword 0x4197DF717D952494
.dword 0xC2951A6F0B8DBE39
.dword 0xC03ED5746F59C789
.dword 0x42FA59537963E1B4
.dword 0xC2A315AFA8134D10
.dword 0x4148938796EE7745
.dword 0x407E342BEC2576C0
.dword 0xC22F312BB121F396
.dword 0xC3E1D3FDD3278C9E
.dword 0x41AD6C15EE7A80F7
.dword 0xC37F6B36E49FC76A
.dword 0x40B8872E7842D5AC
.dword 0x4031C5E6DD955E20
.dword 0x414E1DE68D96A04A
.dword 0x40680FAEFDD79FFB
.dword 0xC2395219E32FEC5B
.dword 0x4071BC8C54CF17AE
.dword 0xC004678A1B83AA7A
.dword 0x421572E29EB7FC72
.dword 0xC2F54CA9094672D4
.dword 0x40CCEAF3ACBD544C
.dword 0xC083FCC8F314CB10
.dword 0xC16714069F3779CE
.dword 0xC2FB456030C7DCFB
.dword 0xC1AB270852EED5CD
.dword 0xC18CC53D88A6E726
.dword 0xC02F528102029CD3
.dword 0xC33C606368A848AD
.dword 0xC15BD8350C8B31D2
.dword 0xC15E98AD482EE284
.dword 0x415F384ED12CB22D
.dword 0x40526A30A2A82209
.dword 0x408E26C7C1E904DE
.dword 0xC26138955A5BB385
.dword 0xC2E523CA4F116AD4
.dword 0x428DA47C2FF3B8F2
.dword 0xC1C92A863F21F6C5
.dword 0x429153D7BF0B8994
.dword 0x423323239F3FFAF8
.dword 0xC35CF9A8A4F5BF53
.dword 0xC03171DE60246964
.dword 0x42668F055678710D
.dword 0x433C178C03FDD610
.dword 0xC2576982DD236343
.dword 0xC396AF532835DA8C
.dword 0x40793EEE84A0105F
.dword 0x4186CFEF7D9A2F74
.dword 0xC1DBDD5BC8F2D511
.dword 0x401E62668EF32D4F
.dword 0xC2789376CC89373C
.dword 0xC1DC0EB163F1FA7E
.dword 0x4291CDB9F3D16D98
.dword 0xC087C0CB7E2B0025
.dword 0xC0B895007B4EC1C6
.dword 0xC393A7484D2E827A
.dword 0x41C900259D35642E
.dword 0xC31D4B2D071E2E36
.dword 0x43D9FF0EEA4C8727
.dword 0x4101EF142BA5727F
.dword 0xC00C8A81A957A87C
.dword 0xC2C7164EE1EAD292
.dword 0x4230F5FADAC583BC
.dword 0xC3E65C7B31A6E0F4
.dword 0xC2007CB994638703
.dword 0x43AD1D92CEA8DF57
.dword 0x41D659DDD84487FD
.dword 0xC0DAFCDC96313705
.dword 0xC217CEA800DB4BB3
.dword 0xC02CCACEABDF0C27
.dword 0x41874C7482B043D4
.dword 0x4140C3942B26687F
.dword 0xC3A52E28D4D9589F
.dword 0x3FFF68618D0D41EE
.dword 0xC3B56A97D03F4BFB
.dword 0x41D34F6E9D3BD0E6
.dword 0xC10725CB041BB5F6
.dword 0xC061E479BE90C897
.dword 0x400DE0F9EE56A811
.dword 0x4260C7B00B01FE6E
.dword 0x40133388A29E7093
.dword 0xC1367E9954A625D9
.dword 0x424062A9D8235DB9
.dword 0xC195D3AE34751C05
.dword 0xC05F38006909DAE4
.dword 0x4182555D99110C8E
.dword 0xC3440E6727F81C5F
.dword 0xC1612660A9C42158
.dword 0x42F4951452B9616F
.dword 0x40996C09AA77518F
.dword 0x41A525FF85CD6963
.dword 0xC0F5D25D500C1E83
.dword 0x435ABF1B6600CD51
.dword 0x42FD140E92573ECD
.dword 0xC15B90D792898FC6
.dword 0xC0BC7698CD4ECC3E
.dword 0x4246A00EB42E47BB
.dword 0xC1AB72E8359E804E
.dword 0xC1836BC7D801CBC2
.dword 0x428D0A951E14E82F
.dword 0x4316A5966021D7ED
.dword 0x429C3670A0441FCA
.dword 0xC303388705658ADE
.dword 0xC26D2260A20833B8
.dword 0xC0B84451F1D42C5C
.dword 0xC0F0447F20C2B4AD
.dword 0xC2B93D04D81FFDB2
.dword 0x41DBC88EB49156A0
.dword 0xC18781B57747ABED
.dword 0x40BC099449FA5490
.dword 0xC2D91851332FD02E
.dword 0xC17F1A42C045E221
.dword 0x4101CCB8F6A7F4FD
.dword 0xC2402DB651DA5E86
.dword 0x40C56DC8D0F71F27

