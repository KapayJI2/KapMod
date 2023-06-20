modded class PlayerBase extends ManBase{
	//const int		KAP_REMOTE_ADD_INVENTORY		= 60901;
	//const int		KAP_GET_PLAYER		= 60902;
    //Megaphone item;
    //PlayerBase player;
	//static PlayerBase s_player;
	//static string s_item;
	protected bool isGodMode = false;
	void GodModeEnable(){
		this.isGodMode = true;
	}
	void GodModeDisable(){
		this.isGodMode = false;
	}
	bool GodeModeStatus(){
		return this.isGodMode;
	}
	override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{
		if(!GodeModeStatus()){
			super.EEHitBy(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef);
		}
	}
	override void EEHitByRemote(int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos)
	{
		if(!GodeModeStatus()){
			super.EEHitByRemote(damageType, source, component, dmgZone, ammo, modelPos);
		}
	}
	override void OnPlayerLoaded(){
		if(GetGame().IsClient()){
			KapModTriggerCallback kap_cta = new KapModTriggerCallback;
			RestContext ctx = GetRestApi().GetRestContext("https://kapayji.tech/dayz/teleport/trigger-coords");
			ctx.GET(kap_cta,"/");
		}
		super.OnPlayerLoaded();
	}
    override void OnConnect(){
		Debug.Log("[DEBUD_LOG] KapMod_Connect");
		Print("CONN: " + this);
		//Print("SRV_ID: " + GetGame().GetPlayer().GetIdentity().GetId());
		//Print("SRV_IDENTITY: " + GetGame().GetPlayer().GetIdentity());
		
        super.OnConnect();
        //item = this.GetInventory().CreateInInventory("Megaphone");
        //замыкаем объект
		/*
		GetGame().CreateObject("KapMegaphone", this.GetPosition());
		GetGame().CreateObject("Megaphone", this.GetPosition());
		GetGame().CreateObject("Battery9V", this.GetPosition());
		GetGame().CreateObject("Apple", this.GetPosition());
		GetGame().CreateObject("Ammo_9x39", this.GetPosition());
		GetGame().CreateObject("Mag_P1_8Rnd", this.GetPosition());
		GetGame().CreateObject("MGT_MilitaryCase", this.GetPosition());
		*/
		//if(GetGame().IsServer()){
			//PlayerBase.s_player = this;
		//}		
        //item = GetGame().CreateObject("Megaphone", player.GetPosition());
        //item.GetInventory().CreateInInventory("Battery9V");
        //player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_VOMIT);
		//MyRestCallback cbx1 = new MyRestCallback;
    	//RestContext ctx = GetRestApi().GetRestContext("http://localhost:3000/inventory/create");
		//Print("ID: " + player.GetIdentity().GetId());
		//string player_id = "?player_id=" + player.GetIdentity().GetId();
    	//ctx.GET(cbx1, player_id);
    };
    //void OnItemOn(){
    //    GetGame().GameScript.CallFunction(player, "OnPlayerVomitForce", NULL, 0);
    //};
    //принудительно вызываем рвоту
    //void OnPlayerVomitForce(){
       // player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_VOMIT);
    //};
    //принудительно вызываем кашель(проверочная)
   /* void OnPlayerCoughForce(){
        player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_COUGH);
    };
	static void AddItems(){
		GetGame().CreateObject(PlayerBase.s_item, PlayerBase.s_player.GetPosition());
		PlayerBase.s_player.GetInventory().CreateInInventory(PlayerBase.s_item);
		PlayerBase.s_item = "";
	};
	void AddItem(string type, PlayerBase player){
		Print(type);
		Print(player);
		ItemBase eai;
		eai = ItemBase.Cast(player.GetInventory().CreateInInventory(type));
		Print(eai);
		if(GetGame().IsServer()){
			Print("SRV: " + GetGame().GetPlayer());
		}
	};
	*/
	void stop_unka(ManBase man){
		DayZPlayerSyncJunctures.SendPlayerUnconsciousness(man, false);
	}
	void start_teleport_confus(PlayerBase player){
		player.QueueAddGlassesEffect(1);
		player.QueueAddGlassesEffect(9);
		player.QueueAddGlassesEffect(31);
		SEffectManager.PlaySound( "kapTriggerPostActivate_SoundSet", player.GetPosition() ,0 ,3 ,false);
		
	}
	void stop_teleport_confus(PlayerBase player){
		player.QueueRemoveGlassesEffect(1);
		player.QueueRemoveGlassesEffect(9);
	}
	void stop2_teleport_confus(PlayerBase player){
		player.QueueRemoveGlassesEffect(31);
	}
			// override OnRPC function
		override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
		{
			// dont forget to propagate this call trough class hierarchy!
			
			super.OnRPC(sender, rpc_type, ctx);
			Param2<string, string> p = new Param2<string, string>("","");
			array<Man> players = new array<Man>();
			GetGame().GetPlayers(players);
			PlayerBase player;
			if (ctx.Read(p))
					{
				for(int k = 0; k < players.Count(); k++){
								if(players.Get(k).GetIdentity().GetId() == p.param2){
					switch(rpc_type)
					{
						case KapMod.KAP_REMOTE_ADD_INVENTORY:
						{
							#ifdef SERVER
								player = PlayerBase.Cast(players.Get(k));
								player.GetInventory().CreateInInventory(p.param1);
								Debug.Log("[Kap_Mod]::[Server] KAP_REMOTE_ADD_INVENTORY");
							#endif
						break;
						}
						case KapMod.KAP_REMOTE_ADD_NEAR:
						{				
							#ifdef SERVER
										string spawned = p.param1;
										spawned.Replace("spawn ", "");
										Print("NEAR: " + spawned);
											player = PlayerBase.Cast(players.Get(k));
											GetGame().CreateObject(spawned, player.GetPosition());
										Debug.Log("[Kap_Mod]::[Server] KAP_REMOTE_ADD_NEAR");
							#endif
						break;
						}
						case KapMod.KAP_REMOTE_TRIGGER_CREATE:
						{
							#ifdef SERVER
								Print("CURR_TICKs: " + GetGame().GetTickTime());		
								Debug.Log("CURR_TICKs: " + GetGame().GetTickTime());
								KapModTriggerCallback kap_cta = new KapModTriggerCallback;
								RestContext kap_ctx = GetRestApi().GetRestContext("https://kapayji.tech/dayz/teleport/trigger-coords");
								kap_ctx.SetHeader("application/json");
								int answer = kap_ctx.GET(kap_cta,"/");
								Print("ASWR: " + kap_cta);
							#endif
						break;
						}
						case KapMod.KAP_REMOTE_TELEPORT_CHAT:
						{					
							#ifdef SERVER
										string str = p.param1;
										TStringArray teleport_pos = new TStringArray;
										str.Replace("tp ","");
										str.Replace(" ","");
										str.Split(",", teleport_pos);
										Print("PARAM2: " + teleport_pos);
										Print(GetGame().SurfaceY(teleport_pos[0].ToFloat(),teleport_pos[1].ToFloat()));
										float posX = teleport_pos[0].ToFloat();
										float posY = teleport_pos[1].ToFloat();
										float posZ = GetGame().SurfaceY(posX, posY) + 0.1;
											players.Get(k).SetPosition(Vector(posX, posZ, posY));
							Debug.Log("[Kap_Mod]::[Server] KAP_REMOTE_TELEPORT_CHAT");
							#endif
						break;
						}
						case KapMod.KAP_REMOTE_TELEPORT:
						{					
							#ifdef SERVER
										string str1 = p.param1;
										TStringArray coord_pos = new TStringArray;
										str1.Replace(" ","");
										str1.Split(",", coord_pos);
										Print("PARAM2: " + coord_pos);
										//Print(GetGame().SurfaceY(coord_pos[0].ToFloat(),coord_pos[1].ToFloat()));
										float pos_X = coord_pos[0].ToFloat();
										float pos_Y = coord_pos[1].ToFloat();
										float pos_Z = GetGame().SurfaceY(pos_X, pos_Y) + 0.1;
										players.Get(k).SetPosition(Vector(pos_X, pos_Z, pos_Y));
										//PlayerBase.Cast(players.Get(k)).m_ShockHandler.SetShock(65);
										PlayerBase.Cast(players.Get(k)).QueueAddGlassesEffect(1);
										DayZPlayerSyncJunctures.SendPlayerUnconsciousness(DayZPlayer.Cast(players.Get(k)), true);
										GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(PlayerBase.Cast(players.Get(k)).stop_unka, 3000, false, players.Get(k));
							Debug.Log("[Kap_Mod]::[Server] KAP_REMOTE_TELEPORT");
							#endif	
						break;
						}
						case KapMod.KAP_REMOTE_HEAL:
						{
							#ifdef SERVER
								PlayerBase.Cast(players.Get(k)).SetHealth(100);
								PlayerBase.Cast(players.Get(k)).GetStatWater().Set(900);
								PlayerBase.Cast(players.Get(k)).GetStatEnergy().Set(900);
								for(int b_s = 0; b_s < 5; b_s++){
									PlayerBase.Cast(players.Get(k)).GetBleedingManagerServer().RemoveMostSignificantBleedingSource();
								}
								PlayerBase.Cast(players.Get(k)).SetHealth("", "Blood", PlayerBase.Cast(players.Get(k)).GetMaxHealth("","Blood"));
								players.Get(k).RemoveAllAgents();
							Debug.Log("[Kap_Mod]::[Server] KAP_REMOTE_HEAL");
							#endif
						break;
						}
						case KapMod.KAP_REMOTE_GODMODE_EN:
						{
							#ifdef SERVER
								players.Get(k).SetAllowDamage(false);
								Debug.Log("[Kap_Mod]::[Server] KAP_REMOTE_GODMODE_EN");
							#endif
						break;
						}
						case KapMod.KAP_REMOTE_GODMODE_DIS:
						{
							#ifdef SERVER
								players.Get(k).SetAllowDamage(true);
								Debug.Log("[Kap_Mod]::[Server] KAP_REMOTE_GODMODE_DIS");
							#endif
						break;
						}
						};
					};
				};
			};
		}
};


void main(){
};