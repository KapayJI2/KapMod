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
			if(GetGame().IsClient()){
				for(int i = 0; i < arr_coords.Count(); i++){
					float posX = arr_coords[i].Get("posX");
					float posZ = arr_coords[i].Get("posZ");
					vector v = Vector(posX,GetGame().SurfaceY(posX,posZ),posZ);
					ParticleSource.CreateParticle(ParticleList.CAMP_NORMAL_FIRE, v, true);
					ParticleSource.CreateParticle(ParticleList.CAMP_NORMAL_SMOKE, v, true);
					Print("Created trigger");
					Debug.Log("Created trigger");
				}
			}
            Print("ERR: " + error);
    };
	};
	override void OnFileCreated( string fileName, int dataSize )
	{
		Print(" !!! OnFileCreated() file=" + fileName + " size=" + dataSize );
	};
};
