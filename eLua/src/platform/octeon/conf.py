# Configuration file for the linux backend

BDK_ROOT = os.getenv("BDK_ROOT")
assert BDK_ROOT, "Define BDK_ROOT in the environment"
specific_files = "platform.c platform-eth.c platform-i2c.c platform-pio.c platform-timer.c platform-uart.c octeon.c"

# Prepend with path
specific_files = " ".join( [ "src/platform/%s/%s" % ( platform, f ) for f in specific_files.split() ] )


# Standard GCC Flags
comp.Append(CCFLAGS = os.getenv("CFLAGS", "").split())
comp.Append(LINKFLAGS = os.getenv("LDFLAGS", "").split())

comp.Append(ASFLAGS = ['-g', '-c', '-x','assembler-with-cpp','-Wall','$_CPPDEFFLAGS'])
comp.Append(LIBS = ['bdk', 'gcc'])
if comp[ 'target' ] == 'lua':
    comp.Append(LIBS = ['m'])

comp['AS'] = toolset[ 'asm' ]  # Need to force toolset

# Toolset data
tools[ 'octeon' ] = {}

# Programming function for octeon (not needed, empty function)
def progfunc_octeon( target, source, env ):
  outname = output + ".elf"
  os.system( "%s %s" % ( toolset[ 'size' ], outname ) )
  print "Visit http://www.eluaproject.net for instructions on how to use your eLua ELF file"

tools[ 'octeon' ][ 'progfunc' ] = progfunc_octeon
