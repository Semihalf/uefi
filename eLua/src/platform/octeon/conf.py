# Configuration file for the linux backend

specific_files = "boot.s platform.c host.c"
specific_files = "boot.s platform.c"
ldscript = "octeon.ld"

# Prepend with path
specific_files = " ".join( [ "src/platform/%s/%s" % ( platform, f ) for f in specific_files.split() ] )
ldscript = "src/platform/%s/%s" % ( platform, ldscript )


# Standard GCC Flags
comp.Append(CCFLAGS = ['-W', '-Wall', '-Wno-unused-parameter', '-g', '-ffunction-sections','-fdata-sections'])
#comp.Append(LINKFLAGS = ['-nostartfiles','-nostdlib','-T',ldscript,'-Wl,--gc-sections','-Wl,--allow-multiple-definition'])
#comp.Append(LINKFLAGS = ['-nostartfiles' ,'-T', ldscript, '-Wl,--allow-multiple-definition', '-Wl,--gc-sections'])
comp.Append(LINKFLAGS = ['-nostartfiles' , '-Wl,--allow-multiple-definition', '-Wl,--gc-sections'])
comp.Append(ASFLAGS = ['-g', '-c', '-x','assembler-with-cpp','-Wall','$_CPPDEFFLAGS'])
#comp.Append(LIBS = ['c','gcc','m'])
if comp[ 'target' ] == 'lua':
    comp.Append(LIBS = ['m'])

TARGET_FLAGS = ['-g', '-march=octeon']

comp.Prepend(CCFLAGS = [TARGET_FLAGS,'-fno-builtin'])
comp.Prepend(LINKFLAGS = [TARGET_FLAGS,'-Wl,-e,__start'])
comp['AS'] = toolset[ 'asm' ]  # Need to force toolset
#comp.Prepend(ASFLAGS = ['-felf'])

# Toolset data
tools[ 'octeon' ] = {}

# Programming function for octeon (not needed, empty function)
def progfunc_octeon( target, source, env ):
  outname = output + ".elf"
  os.system( "%s %s" % ( toolset[ 'size' ], outname ) )
  print "Visit http://www.eluaproject.net for instructions on how to use your eLua ELF file"

tools[ 'octeon' ][ 'progfunc' ] = progfunc_octeon
