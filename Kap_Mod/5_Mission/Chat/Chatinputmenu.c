// Script File	
modded class ChatInputMenu extends UIScriptedMenu {	
	override bool OnChange(Widget w, int x, int y, bool finished)
	{
		super.OnChange(w, x, y, finished);
				if (!finished) return false;
		
		string text = m_edit_box.GetText();
		if (finished){
			if (text != "")
				{
					Print("TXT: " + text);		
					PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
					//Print(player.GetPosition());
					//player.AddItem(text);
					//GetGame().CreateObject(text, player.GetPosition());
					//MyRestCallback m_cb = new MyRestCallback;
					//RestContext ctx = GetRestApi().GetRestContext("http://localhost:3000/inventory/test");
					//ctx.GET(m_cb,"?message=" + text + "&player_id=" + GetGame().GetPlayer().GetIdentity().GetId());
					//Param param = new Param1<string>(text);
					//GetGame().RPCSingleParam(GetGame().GetPlayer(), ERPCs.DEV_RPC_SPAWN_ITEM_IN_INVENTORY, param, true, GetGame().GetPlayer().GetIdentity());
				/*	Print("PLR: " + PlayerBase.Cast(GetGame().GetPlayer()));
					Print("MAN: " + Man.Cast(GetGame().GetPlayer()));
					Print("ID: " + GetGame().GetPlayer().GetIdentity());
					//GetGame().GetPlayer().GetInventory().CreateInInventory(text);
								Param param = new Param2<string, PlayerBase>(text, PlayerBase.Cast(GetGame().GetPlayer()));
				GetGame().GameScript.CallFunctionParams(GetGame().GetPlayer(), "AddItem", NULL, param);
				if(GetGame().IsServer()){
					Print("IsServer");
				}
				};*/
				//Param4<string, float, float, vector> params = new Param4<string, float, float, vector>(text, 100, 1, GetGame().GetPlayer().GetPosition());
				//player.RPCSingleParam(ERPCs.DEV_RPC_SPAWN_ITEM_IN_INVENTORY, params, true);
				//Param5<string, float, float, bool> params = new Param4<string, float, float, bool>(text, 100, 1, false);
				//player.RPCSingleParam(ERPCs.DEV_RPC_SPAWN_ITEM_IN_INVENTORY, params, true);
				string p_ID = GetGame().GetPlayer().GetIdentity().GetId();
				Param params = new Param2<string, string>(text, p_ID);
				GetGame().RPCSingleParam(GetGame().GetPlayer(), KapMod.KAP_REMOTE_ADD_INVENTORY, params, true);
		};
		};
		return true;
	};
};