
proc when_I_run_through_profiler { } {

  global asparagus_executable_path
  global asparagus_spawn_id

  set asparagus_spawn_id ""

  if { [ catch { spawn "graprof" -FCM $asparagus_executable_path } msg ] } {
    fail_step "$msg"
    return
  }

  # give the program a bit of time
  after 10

  set asparagus_spawn_id "$spawn_id"

  pass_step

}
asparagus_register_step when_I_run_through_profiler "when I run through profiler"
