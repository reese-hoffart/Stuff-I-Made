#cs ----------------------------------------------------------------------------

 AutoIt Version: 3.3.14.5
 Author:         myName

 Script Function:
	Template AutoIt script.

#ce ----------------------------------------------------------------------------

; Script Start - Add your code below here
#include <GUIConstantsEx.au3>
#include <WindowsConstants.au3>
#include <Date.au3>

$color = 0xffffffff

$myGUI = GUICreate("Invis Window", 1920, 1080, -1, 1)
GUISetBkColor($color, $myGUI)
GUISetState(@SW_SHOWMAXIMIZED, $myGUI)
;GUISetState(@SW_SHOW, $myGUI)
WinSetTrans($myGUI, "", 1)

;Global $lastDate = _NowCalc()
While 1
	;If _DateDiff('s', $lastDate, _NowCalc()) >= 30 Then
	;	$lastDate = _NowCalc()
	;	WinActivate("Program Manager")
	;	WinActivate("Invis Window")
	;EndIf
	Switch GUIGetMsg()
		Case $GUI_EVENT_CLOSE, $myGUI
			ExitLoop
	EndSwitch
WEnd
GUIDelete($myGUI)