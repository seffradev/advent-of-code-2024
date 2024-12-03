project(
  'advent-of-code',
  'cpp',
  version: '1.0.0',
  default_options: ['cpp_std=c++23', 'warning_level=3'],
)

includes = include_directories('include')

project_source_files = ['src/main.cc']

day1_sources = ['src/day1.cc']

day1 = static_library('day1', day1_sources, include_directories: includes, install: true)

executable(
  meson.project_name(),
  project_source_files,
  install: true,
  include_directories: includes,
  link_with: day1,
)

day1_tests = executable('day1_tests', ['tests/day1.cc'], include_directories: includes, link_with: day1)

test('day1_tests', day1_tests)
