#!/bin/sh

pkill dunst
../dunst -conf ./dunstrc &

echo "Move to empty workspace"

sleep 2

rm -r promo-pics
mkdir promo-pics

SIZE="803,0 1116x260"

# grim -g "1330,0 590x260" -t png ./otherconfig.png

dunstify -i "$PWD"/data/dirt.jpg "Now Playing" '<b>Rooster</b>
by <i>Alice in Chains</i>
from <i>Dirt</i>'

sleep 0.1

grim -g "$SIZE" -t png ./promo-pics/music.png


pkill dunst
../dunst -conf ./dunstrc &
echo "42" | progress-notify audio
echo "60" | progress-notify brightness

sleep 0.1

grim -g "$SIZE" -t png ./promo-pics/audio.png


pkill dunst
../dunst -conf ./dunstrc &
notify-send -u critical -i /usr/share/icons/gnome/scalable/status/battery-low-symbolic.svg "Battery is getting low"
notify-send -u normal -i /usr/share/icons/gnome/scalable/actions/mail-send-receive-symbolic.svg "You have 1 new email"
notify-send -u low -i /usr/share/icons/gnome/scalable/places/network-server-symbolic.svg "Connected to network server"

sleep 0.1

grim -g "$SIZE" -t png ./promo-pics/urgency.png


pkill dunst
../dunst -conf /etc/dunst/dunstrc &
notify-send -u critical -i /usr/share/icons/gnome/scalable/status/battery-low-symbolic.svg "Battery is getting low"
notify-send -u normal -i /usr/share/icons/gnome/scalable/actions/mail-send-receive-symbolic.svg "You have 1 new email"
notify-send -u low -i /usr/share/icons/gnome/scalable/places/network-server-symbolic.svg "Connected to network server"

sleep 0.1

grim -g "$SIZE" -t png ./promo-pics/default_config.png


## Kill dunst in the end
pkill dunst
