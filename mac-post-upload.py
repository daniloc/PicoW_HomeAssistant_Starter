# Clear the obnoxious disk ejected alerts in macOS
import platform
from subprocess import Popen, PIPE
Import("env")


def after_upload(source, target, env):
    scpt = '''
        on run
                tell application "System Events"
                tell application process "NotificationCenter"
                    repeat while exists (UI elements of scroll area 1 of window 1)
                        try
                            perform (first action of group 1 of UI element 1 of ¬
                                scroll area 1 of windows where description is "Close")
                        end try
                        delay 1
                    end repeat
                end tell
            end tell
        end run'''
    args = ['2', '2']

    p = Popen(['osascript', '-'] + args, stdin=PIPE, stdout=PIPE, stderr=PIPE)

    stdout, stderr = p.communicate(scpt.encode())
    print (p.returncode, stdout, stderr)

if(platform.system() == "Darwin"):
    env.AddPostAction("upload", after_upload)
