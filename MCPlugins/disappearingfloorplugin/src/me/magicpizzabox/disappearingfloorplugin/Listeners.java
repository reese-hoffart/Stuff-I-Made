package me.magicpizzabox.disappearingfloorplugin;

import org.bukkit.Location;
import org.bukkit.Material;
import org.bukkit.entity.Player;
import org.bukkit.event.EventHandler;
import org.bukkit.event.Listener;
import org.bukkit.event.player.PlayerMoveEvent;

public class Listeners implements Listener {
	
	private Location lastLocation = new Location (null, 0, 0, 0);

    @EventHandler
    public void onMove(PlayerMoveEvent e) {
        Player player = e.getPlayer();
        Location loc = player.getLocation();
        if(Math.abs(loc.getBlockX() - lastLocation.getBlockX()) >= 2 ||
        Math.abs(loc.getBlockY() - lastLocation.getBlockY()) >= 2 ||
        Math.abs(loc.getBlockZ() - lastLocation.getBlockZ()) >= 2) {
        	lastLocation = loc;
	        player.getLocation().add(0, -1, 0).getBlock().setType(Material.AIR);
	        player.getLocation().add(1, -1, 0).getBlock().setType(Material.AIR);
	        player.getLocation().add(1, -1, 1).getBlock().setType(Material.AIR);
	        player.getLocation().add(0, -1, 1).getBlock().setType(Material.AIR);
	        player.getLocation().add(-1, -1, 0).getBlock().setType(Material.AIR);
	        player.getLocation().add(-1, -1, -1).getBlock().setType(Material.AIR);
	        player.getLocation().add(0, -1, -1).getBlock().setType(Material.AIR);
	        player.getLocation().add(1, -1, -1).getBlock().setType(Material.AIR);
	        player.getLocation().add(-1, -1, 1).getBlock().setType(Material.AIR);
        }
    }
}