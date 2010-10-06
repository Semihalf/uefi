# Configuration file for the linux backend

BDK_ROOT = os.getenv("BDK_ROOT")
assert BDK_ROOT, "Define BDK_ROOT in the environment"
specific_files = "boot.s platform.c platform-eth.c platform-i2c.c platform-pio.c platform-pwm.c platform-spi.c platform-timer.c platform-uart.c"

# Prepend with path
specific_files = " ".join( [ "src/platform/%s/%s" % ( platform, f ) for f in specific_files.split() ] )


# Standard GCC Flags
comp.Append(CCFLAGS = ['-W', '-Wall', '-Wno-unused-parameter', '-g', '-ffunction-sections','-fdata-sections', '-I' + BDK_ROOT])
comp.Append(LINKFLAGS = ['-nostartfiles' , '-Wl,--allow-multiple-definition', '-Wl,--gc-sections', '-L' + BDK_ROOT])
comp.Append(ASFLAGS = ['-g', '-c', '-x','assembler-with-cpp','-Wall','$_CPPDEFFLAGS'])
comp.Append(LIBS = ['bdk'])
if comp[ 'target' ] == 'lua':
    comp.Append(LIBS = ['m'])

TARGET_FLAGS = ['-g', '-march=octeon']

comp.Prepend(CCFLAGS = [TARGET_FLAGS,'-fno-builtin'])
comp.Prepend(LINKFLAGS = [TARGET_FLAGS,'-Wl,-e,__start'])
comp['AS'] = toolset[ 'asm' ]  # Need to force toolset

# Toolset data
tools[ 'octeon' ] = {}

# Programming function for octeon (not needed, empty function)
def progfunc_octeon( target, source, env ):
  outname = output + ".elf"
  os.system( "%s %s" % ( toolset[ 'size' ], outname ) )
  print "Visit http://www.eluaproject.net for instructions on how to use your eLua ELF file"

tools[ 'octeon' ][ 'progfunc' ] = progfunc_octeon
