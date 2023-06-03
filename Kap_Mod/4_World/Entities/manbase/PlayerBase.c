modded class PlayerBase extends ManBase{
	//const int		KAP_REMOTE_ADD_INVENTORY		= 60901;
	//const int		KAP_GET_PLAYER		= 60902;
    //Megaphone item;
    //PlayerBase player;
	//static PlayerBase s_player;
	//static string s_item;
    override void OnConnect(){
		Debug.Log("[DEBUD_LOG] KapMod_Connect");
		Print("CONN: " + this);
		Print("SRV_ID: " + GetGame().GetPlayer().GetIdentity().GetId());
		Print("SRV_IDENTITY: " + GetGame().GetPlayer().GetIdentity());
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
			// override OnRPC function
		override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
		{
			// dont forget to propagate this call trough class hierarchy!
			Debug.Log("[DEBUD_LOG] KapMod_RPC");
			if(GetGame().IsServer())
						{
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
									player = PlayerBase.Cast(players.Get(k));
									GetGame().CreateObject(p.param1, player.GetPosition());
				break;
							}
				case KapMod.KAP_REMOTE_TELEPORT:
				{
									player = PlayerBase.Cast(players.Get(k));
									player.SetPosition(p.param2.ToVector());
				break;
				}
						};
					};
		};
			};
			};
			super.OnRPC(sender, rpc_type, ctx);
		}
};


void main(){
};