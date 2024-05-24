project(
    'lwm',
    'c',
    version: '0.1',
    default_options: ['warning_level=3', 'c_std=c11'],
    license: 'GNU GPLv3',
)

subdir('src')

xlib_dep = dependency('X11')

executable('lwm', sources: sources, install: true, dependencies: [xlib_dep])