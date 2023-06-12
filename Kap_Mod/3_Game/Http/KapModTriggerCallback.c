// Script File// Script File
class ResponseTriggerApi{
	string func_name;
	string netId;
	array<map<string, float>> coords;
}

class KapModTriggerCallback: RestCallback {
    override void OnSuccess( string data, int dataSize )
    {
        // override this with your implementation
        Print(" !!! OnSuccess() size=" + dataSize );
		Print("Success");
        if( dataSize > 0 ){
            Print("DATA: " + data); // !!! NOTE: Print() will not output string longer than 1024b, check your dataSize !!!
            ResponseTriggerApi resp = new ResponseTriggerApi;
			array<map<string, float>> arr_coords = new array<map<string, float>>();
            string error;
            JsonSerializer js = new JsonSerializer();
            bool ok = js.ReadFromString(resp, data, error);
			string f_name = resp.func_name;
			string playerId = resp.netId;
			arr_coords = resp.coords;
			for(int i = 0; i < arr_coords.Count(); i++){
				float posX = arr_coords[i].Get("posX");
				float posZ = arr_coords[i].Get("posZ");
				vector v = Vector(posX,GetGame().SurfaceY(posX,posZ),posZ);
				if(GetGame().IsClient()){
					ParticleSource.CreateParticle(ParticleList.CAMP_NORMAL_FIRE, v, true);
					ParticleSource.CreateParticle(ParticleList.CAMP_NORMAL_SMOKE, v, true);
					Print("[Kap_Mod] Created particle num: " + i + ", on pos: " + v);
					Debug.Log("[Kap_Mod] Created particle num: " + i + ", on pos: " + v);
				}
				#ifdef SERVER
					GetGame().CreateObjectEx("KapTrigger", v, ECE_SETUP);
					Print("[Kap_Mod] Created trigger num: " + i +", on pos: " + v);
					Debug.Log("[Kap_Mod] Created trigger num: " + i +", on pos: " + v);
				
				#endif
			}
            Print("ERR: " + error);
    };
	};
};
