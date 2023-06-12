modded class PlayerBase extends ManBase{
	//const int		KAP_REMOTE_ADD_INVENTORY		= 60901;
	//const int		KAP_GET_PLAYER		= 60902;
    //Megaphone item;
    //PlayerBase player;
	//static PlayerBase s_player;
	//static string s_item;
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
			// override OnRPC function
		override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
		{
			// dont forget to propagate this call trough class hierarchy!
			Debug.Log("[DEBUD_LOG] KapMod_RPC");
			#ifdef SERVER
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
											player = PlayerBase.Cast(players.Get(k));
											player.GetInventory().CreateInInventory(p.param1);
						break;
						}
						case KapMod.KAP_REMOTE_ADD_NEAR:
						{				
										string spawned = p.param1;
										spawned.Replace("spawn ", "");
										Print("NEAR: " + spawned);
											player = PlayerBase.Cast(players.Get(k));
											
											GetGame().CreateObject(spawned, player.GetPosition());
						break;
						}
						case KapMod.KAP_REMOTE_TELEPORT_CHAT:
						{					
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
						break;
						}
						case KapMod.KAP_REMOTE_TELEPORT:
						{					
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
										DayZPlayerSyncJunctures.SendPlayerUnconsciousness(players.Get(k), true);
										GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(PlayerBase.Cast(players.Get(k)).stop_unka, 3000, false, players.Get(k));
										
										
						break;
						}
						case KapMod.KAP_REMOTE_HEAL:
						{
								PlayerBase.Cast(players.Get(k)).SetHealth(100);
								PlayerBase.Cast(players.Get(k)).SetBleedingBits(0);
								players.Get(k).RemoveAllAgents();
						break;
						}
						};
					};
				};
			};
			#endif
			super.OnRPC(sender, rpc_type, ctx);
		}
};


//void main(){
//};