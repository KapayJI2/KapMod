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
							//	Print("PLR: " + PlayerBase.Cast(GetGame().GetPlayer()));
							//Print("MAN: " + Man.Cast(GetGame().GetPlayer()));
							//Print("ID: " + GetGame().GetPlayer().GetIdentity());
							//GetGame().GetPlayer().GetInventory().CreateInInventory(text);
							//			Param param = new Param2<string, PlayerBase>(text, PlayerBase.Cast(GetGame().GetPlayer()));
							//GetGame().GameScript.CallFunctionParams(GetGame().GetPlayer(), "AddItem", NULL, param);
							//Param4<string, float, float, vector> params = new Param4<string, float, float, vector>(text, 100, 1, GetGame().GetPlayer().GetPosition());
							//player.RPCSingleParam(ERPCs.DEV_RPC_SPAWN_ITEM_IN_INVENTORY, params, true);
							//Param5<string, float, float, bool> params = new Param4<string, float, float, bool>(text, 100, 1, false);
							//player.RPCSingleParam(ERPCs.DEV_RPC_SPAWN_ITEM_IN_INVENTORY, params, true);
					string p_ID = GetGame().GetPlayer().GetIdentity().GetId();
					Debug.Log("[DEBUD_LOG] Kap_Mod Chat");
					Param params = new Param2<string, string>(text, p_ID);
					//Param params = new Param1<string>(text);
					Print(KapMod.KAP_REMOTE_ADD_INVENTORY);
					GetGame().RPCSingleParam(GetGame().GetPlayer(), KapMod.KAP_REMOTE_ADD_INVENTORY, params, true, GetGame().GetPlayer().GetIdentity());
					//GetGame().RPCSingleParam(GetGame().GetPlayer(), KapMod.KAP_REMOTE_ADD_INVENTORY, params, true);
					//GetGame().RPCSingleParam(GetGame().GetPlayer(), KapMod.KAP_REMOTE_ADD_INVENTORY, params, false, GetGame().GetPlayer().GetIdentity());
					//GetGame().RPCSingleParam(GetGame().GetPlayer(), KapMod.KAP_REMOTE_ADD_INVENTORY, params, false);
					//GetGame().RPCSingleParam(null, 60901, params, true,GetGame().GetPlayer().GetIdentity());
					//GetGame().RPCSingleParam(GetGame().GetPlayer(), ERPCs.DEV_RPC_SPAWN_ITEM_ON_GROUND, new Param4<string, float, float, bool>(text, 100, 1, false), true, GetGame().GetPlayer().GetIdentity());
					//GetGame().RPCSingleParam(GetGame().GetPlayer(), ERPCs.DEV_RPC_SPAWN_ITEM_ON_GROUND, new Param4<string, float, float, bool>(text, 100, 1, false), true);
					//GetGame().RPCSingleParam(null, ERPCs.DEV_RPC_SPAWN_ITEM_ON_GROUND, new Param4<string, float, float, bool>(text, 100, 1, false), true, GetGame().GetPlayer().GetIdentity());
					//array<Param> a_p = new array<Param>;
					//a_p.Insert(params);
					//GetGame().RPC(GetGame().GetPlayer(), KapMod.KAP_REMOTE_ADD_INVENTORY, a_p, true, GetGame().GetPlayer().GetIdentity());
					//GetGame().RPC(null, KapMod.KAP_REMOTE_ADD_INVENTORY, a_p, true, GetGame().GetPlayer().GetIdentity());
					//GetCEApi().SpawnDE("StaticHeliCrash", player.GetPosition());
				};
			
			
			};
		return true;
		};
		
};