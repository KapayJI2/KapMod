// Script File	
modded class ChatInputMenu extends UIScriptedMenu {	
	override bool OnChange(Widget w, int x, int y, bool finished)
	{
				if (!finished) return false;
		
		string text = m_edit_box.GetText();
		if (finished){
			if (text != "")
				{
				string BASE_URL = "https://kapayji.tech/dayz";
				RestContext ctx;
				string p_ID = GetGame().GetPlayer().GetIdentity().GetId();
				KapModCallback m_cb = new KapModCallback;
				Param params = new Param2<string, string>(text, p_ID);
				if(text.IndexOf("trcr") != -1){
					GetGame().RPCSingleParam(GetGame().GetPlayer(), KapMod.KAP_REMOTE_TRIGGER_CREATE, params, true, GetGame().GetPlayer().GetIdentity());
				}else if(text.IndexOf("menu") != -1){
					string URL = "http://localhost:3000";
					KapModWidgetCallback cbk = new KapModWidgetCallback;
					RestContext ctx_widget = GetRestApi().GetRestContext(URL);
					ctx_widget.GET(cbk,"/lines");
				}else if(text.IndexOf("off") != -1){
					GetGame().RPCSingleParam(GetGame().GetPlayer(), KapMod.KAP_REMOTE_GODMODE_DIS, params, true, GetGame().GetPlayer().GetIdentity());
				}else if(text.IndexOf("iddqd") != -1){
					GetGame().RPCSingleParam(GetGame().GetPlayer(), KapMod.KAP_REMOTE_GODMODE_EN, params, true, GetGame().GetPlayer().GetIdentity());
				}else if(text.IndexOf("goto") != -1){
						TStringArray str_arr = new TStringArray;
						text.Split(" ", str_arr);
						ctx = GetRestApi().GetRestContext(BASE_URL + "/teleport/pos-move/");
						ctx.GET(m_cb,p_ID + "/" + str_arr[1]);
				}else if(text == "rndtp"){
						ctx = GetRestApi().GetRestContext(BASE_URL + "/teleport/rand-move/");
						ctx.GET(m_cb,p_ID);
				}else if(text == "heal"){
						PlayerBase.Cast(GetGame().GetPlayer()).SetBleedingBits(0);
						GetGame().RPCSingleParam(GetGame().GetPlayer(), KapMod.KAP_REMOTE_HEAL, params, true, GetGame().GetPlayer().GetIdentity());
				}else if(text == "pos"){
					string pos = GetGame().GetPlayer().GetPosition().ToString();
					GetGame().RPCSingleParam(GetGame().GetPlayer(), ERPCs.RPC_USER_ACTION_MESSAGE, new Param1<string>(GetGame().GetPlayer().GetPosition().ToString()),true, GetGame().GetPlayer().GetIdentity());
					GetGame().RPCSingleParam(ManBase.Cast(GetGame().GetPlayer()), ERPCs.RPC_USER_ACTION_MESSAGE, new Param1<string>("MAN: " + GetGame().GetPlayer().GetPosition().ToString()),true, GetGame().GetPlayer().GetIdentity());
				}else if(text.IndexOf("spawn") != -1){
						Debug.Log("[DEBUD_LOG] Kap_Mod Chat NEAR");
						GetGame().RPCSingleParam(GetGame().GetPlayer(), KapMod.KAP_REMOTE_ADD_NEAR, params, true, GetGame().GetPlayer().GetIdentity());
					}else if(text.IndexOf("tp") != -1){
						Debug.Log("[DEBUD_LOG] Kap_Mod Chat TELEPORT");
						GetGame().RPCSingleParam(GetGame().GetPlayer(), KapMod.KAP_REMOTE_TELEPORT_CHAT, params, true, GetGame().GetPlayer().GetIdentity());
					}else /*if(text.IndexOf("/part") != -1){
						vector v = Vector(2651.72, GetGame().SurfaceY(2651.72,1380.47) ,1380.47);
						ParticleSource.CreateParticle(ParticleList.CAMP_NORMAL_FIRE, v, true);
						ParticleSource.CreateParticle(ParticleList.CAMP_NORMAL_SMOKE, v, true);
						Print("Created trigger");
						Debug.Log("Created trigger");
					}else*/{
					Print("TXT: " + text);		
					//GetGame().ExecuteEnforceScript --------------------------!
					PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
					Debug.Log("[DEBUD_LOG] Kap_Mod Chat INV");
					Print(KapMod.KAP_REMOTE_ADD_INVENTORY);
					GetGame().RPCSingleParam(GetGame().GetPlayer(), KapMod.KAP_REMOTE_ADD_INVENTORY, params, true, GetGame().GetPlayer().GetIdentity());
				};
			};
			
			
			};
		super.OnChange(w, x, y, finished);
		return true;
		};
		
};