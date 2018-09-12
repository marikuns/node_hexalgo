from distutils.core import setup, Extension

module1 = Extension('pyhashhex',
                    sources = ['hex_py.c','hex.c',
                    'sph/whirlpool.c',
                    'sph/simd.c',
                    'sph/shabal.c',
                    'sph/shavite.c',
                    'sph/hamsi.c',
                    'sph/keccak.c',
                    'sph/hamsi.c',
                    'sph/groestl.c',
                    'sph/cubehash.c',
                    'sph/echo.c',
                    'sph/blake.c',
                    'sph/skein.c',
                    'sph/luffa.c',
                    'sph/sha2.c',
                    'sph/jh.c',
                    'sph/fugue.c',
                    'sph/bmw.c',
                    'sph/sha2big.c'
                  
                    
                    
                    
                    
                    ],include_dirs=['./sph','.'])
setup (name = 'Pyhashhex',
       version = '1.0',
       description = 'HEX hasher',
       ext_modules = [module1])