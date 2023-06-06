// Script File
/*
class KapTriggerParent {
	protected KapTrigger kap_trigger;

    override void EEInit()
	{
        super.EEInit();
        if (GetGame().IsServer())
		{
			CreateTrigger();
        }
	}

    override void EEDelete(EntityAI parent)
	{
		super.EEDelete(parent);

		if ( GetGame() && kap_trigger )
		{
			GetGame().ObjectDelete( kap_trigger );
			kap_trigger = null;
		}
	}
	override void OnEnter(Object obj){
		PlayerBase player;
		Print("CAST: " + Class.CastTo(player, obj));
		if(Class.CastTo(player, obj)){
			Print("PLR: " + player);
			GetGame().RPCSingleParam(player, ERPCs.RPC_USER_ACTION_MESSAGE, new Param1<string>("Вы в зоне триггера"),true, player.GetIdentity());
		}else{
			Print("FALSE");
		}
		Print("ENTER");
	}
	void CreateTrigger(){
        if (Class.CastTo(kap_trigger, GetGame().CreateObjectEx("KapTrigger", GetPosition(), ECE_CREATEPHYSICS)))
		{
            float radius = 20;
            float height = 20;

			vector mins = vector.Zero; mins[0] = -radius; mins[2] = -radius; mins[1] = -height;
			vector maxs = vector.Zero; maxs[0] =  radius; maxs[2] =  radius; maxs[1] =  height;

			kap_trigger.SetOrientation(GetOrientation());
			kap_trigger.SetExtents(mins, maxs);
			kap_trigger.SetParentObject(this);
		}
    }
	
}

*/
class KapTrigger: Trigger{
    //protected KapTriggerParent kap_Parent;

   // void SetParentObject( KapTriggerParent obj )
	//{
	//	kap_Parent = obj;
	//}

    override void OnEnter(Object obj){
		Object obj2;
		Print("CAST: " + Man.CastTo(obj2, obj));
		if(Man.CastTo(obj2, obj)){
			Print("PLR: " + PlayerBase.Cast(obj2));
			Man man = Man.Cast(obj2);
			Print("MAN: " + man);
			GetGame().RPCSingleParam(man, ERPCs.RPC_USER_ACTION_MESSAGE, new Param1<string>("Вы в зоне триггера"),true, man.GetIdentity());
			string p_ID = man.GetIdentity().GetId();
			Print("ID: " + p_ID);
			MyRestCallback m_cb_rand = new MyRestCallback;
			string url = "http://localhost:3000/teleport/rand-move/";
			RestContext ctx = GetRestApi().GetRestContext(url);
			ctx.GET(m_cb_rand,p_ID);
		}else{
			Print("FALSE");
		}
		Print("PLR_THIS: " + GetGame().GetPlayer());
		Print("ENTER");
	}
}