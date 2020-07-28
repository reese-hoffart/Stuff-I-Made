package me.magicpizzabox.disappearingfloorplugin;

import org.bukkit.plugin.java.JavaPlugin;

public class Main extends JavaPlugin {

	@Override
	public void onEnable() {
		getServer().getPluginManager().registerEvents(new Listeners(), this);
		System.out.println("DisappearingFloor Plugin Enabled!");
	}
	
	@Override
	public void onDisable() {}
}
