// Script File
class ResponseKapBack
{
	string func_name;
	string netId;
    array<string> func_args;
};

class KapModCallback: RestCallback {
    override void OnSuccess( string data, int dataSize )
    {
        // override this with your implementation
        Print(" !!! OnSuccess() size=" + dataSize );
		Print("Success: " + GetGame().IsServer());
        if( dataSize > 0 ){
            Print("DATA: " + data); // !!! NOTE: Print() will not output string longer than 1024b, check your dataSize !!!
            ResponseKapBack resp = new ResponseKapBack;
            string error;
            JsonSerializer js = new JsonSerializer();
            bool ok = js.ReadFromString(resp, data, error);
			string f_name = resp.func_name;
			string playerId = resp.netId;
			if(f_name == "teleport"){
				string posX;
				string posZ;
				if(resp.func_args.Count() > 0){
					posX = resp.func_args[0];
					posZ = resp.func_args[1];
					Param param = new Param2<string, string>(posX + "," + posZ,playerId);
					GetGame().RPCSingleParam(GetGame().GetPlayer(), KapMod.KAP_REMOTE_TELEPORT, param, true, GetGame().GetPlayer().GetIdentity());
				}else{
					error = "Coords empty";
				};
			};
            Print("ERR: " + error);
    };
	};
};
