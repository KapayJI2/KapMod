// Script File
modded class MissionServer extends MissionBase{
	override void OnInit()
	{
		super.OnInit();
		KapModTriggerCallback kap_cta = new KapModTriggerCallback;
		RestContext ctx = GetRestApi().GetRestContext("https://kapayji.tech/dayz/teleport/trigger-coords");
		ctx.GET(kap_cta,"/");
		/*
		#ifdef SERVER
			ResponseTriggerApi rta = new ResponseTriggerApi;
			RestContext ctx = GetRestApi().GetRestContext("https://kapayji.tech/dayz/teleport/trigger-coords");
			string ctx_int = ctx.GET_now("/");
			array<map<string, float>> arr_coords = new array<map<string, float>>();
			string error;
			JsonSerializer js = new JsonSerializer();
			bool ok = js.ReadFromString(rta, ctx_int, error);
			arr_coords = rta.coords;
			for(int i = 0; i < arr_coords.Count(); i++){
				float posX = arr_coords[i].Get("posX");
				float posZ = arr_coords[i].Get("posZ");
				vector v = Vector(posX,GetGame().SurfaceY(posX,posZ),posZ);
				GetGame().CreateObjectEx("KapTrigger", v, ECE_SETUP);
				Print("Created trigger");
				Debug.Log("Created trigger");
			}
			if(error != ""){
				Debug.Log("Error: " + error);
			}
		#endif
		*/
	}
}