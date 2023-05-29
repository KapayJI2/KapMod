// Script File
class ResponseFromBack
{
    array<string> items;
	string id;
};

class MyRestCallback: RestCallback {
    override void OnSuccess( string data, int dataSize )
    {
        // override this with your implementation
        Print(" !!! OnSuccess() size=" + dataSize );
		Print("Success: " + GetGame().IsServer());
        if( dataSize > 0 ){
            //Print(data); // !!! NOTE: Print() will not output string longer than 1024b, check your dataSize !!!
            ResponseFromBack resp = new ResponseFromBack();
            string error;
            JsonSerializer js = new JsonSerializer();
            bool ok = js.ReadFromString(resp, data, error);
            array<Man> players = new array<Man>;
			GetGame().GetPlayers(players);
			//PlayerBase player;
			Man player;
			Object obj;
			EntityAI eai;
			for(int k = 0; k < players.Count(); k++){
				if(players.Get(k).GetIdentity().GetId() == resp.id){
					//Class.CastTo(player ,players.Get(k));
					player = players.Get(k);
					Print("PLRS: " + players.Get(k));
					Print("PLR: " + player);
				};
			};
            for(int i = 0; i < resp.items.Count(); i++){
                Print(resp.items.Get(i));
				string item_name = resp.items.Get(i);
				//Param param2 = new Param2< string, PlayerBase >(item_name, player);
				//GetGame().GameScript.CallFunctionParams( player, "AddItem", NULL, param2 );
				//ItemBase.Cast(player.GetInventory().CreateInInventory(item_name));
				Param param = new Param1<string>(item_name);
				GetGame().GameScript.CallFunctionParams(NULL, "AddItemTo", NULL, param);
				Print(GetGame().RPCSingleParam(player, ERPCs.DEV_RPC_SPAWN_ITEM_IN_INVENTORY, param, true, player.GetIdentity()));
				//AddItem(item_name, player);
				//obj = GetGame().CreateObject(item_name, player.GetPosition());
				//Print("OBJ: " + obj);
				//eai = player.GetInventory().CreateInInventory(item_name);
				//Print("EAI: " + eai);
				
				//PlayerBase.s_item = resp.items.Get(i);
				//PlayerBase.AddItems();
            };
            Print("ERR: " + error);
        };
    };
	override void OnFileCreated( string fileName, int dataSize )
	{
		Print(" !!! OnFileCreated() file=" + fileName + " size=" + dataSize );
	};
};

void AddItemTo(string item){
	PlayerBase player = GetGame().GetPlayer();
	player.GetInventory().CreateInInventory(item);
};